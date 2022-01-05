//
// Created by chunxiao ma on 2021/11/3.
//

#include "code/binaryFileParser.hh"

#include <cassert>
#include <cstdio>

namespace pvm {

BinaryFileParser::BinaryFileParser(BufferedInputStream *stream) { _stream = stream; }

CodeObject *BinaryFileParser::Parse() {
  /*
   * MagicNumber:
   * Timestamp:
   * Size:
   *
   * Type:
   * ArgCount:
   * KwOnlyArgCount:
   * NumLocals:
   * StackSize:
   * Flags:
   *
   */
  int magic_number = _stream->ReadInt();
  int mod_data = _stream->ReadInt();
  char object_type = _stream->Read();
  printf("magic number= 0x%x\n", magic_number);
  printf("mod data    = 0x%x\n", mod_data);
  printf("object type = %c\n", object_type);
  CodeObject *codeObject = nullptr;
  if ('c' == object_type) {
    codeObject = ReadCode();
    printf("parse file  = done\n");
  } else {
  }
  return codeObject;
}

CodeObject *BinaryFileParser::ReadCode() {
  int argc = _stream->ReadInt();
  int n_locals = _stream->ReadInt();
  int stack_size = _stream->ReadInt();
  int flags = _stream->ReadInt();
  PyString *bytecode = ReadBytecode();
  ArrayList<PyObject *> *consts = ReadConsts();
  ArrayList<PyObject *> *names = ReadNames();
  ArrayList<PyObject *> *var_names = ReadVarNames();
  ArrayList<PyObject *> *free_vars = ReadFreeVars();
  ArrayList<PyObject *> *cell_vars = ReadCellVars();

  PyString *filename = ReadFilename();
  PyString *name = ReadName();
  printf("argc        = %d\n", argc);
  printf("n_locals    = %d\n", n_locals);
  printf("stack_size  = %d\n", stack_size);
  printf("flags       = %d\n", flags);
  printf("byte_codes  = %p\n", bytecode);
  return new CodeObject(filename, name, argc, 0, 0, n_locals, stack_size, flags, bytecode, consts, names, var_names,
                        cell_vars, free_vars);
}

PyString *BinaryFileParser::ReadFilename() { return ReadName(); }
PyString *BinaryFileParser::ReadName() {
  char ch = _stream->Read();
  PyString *ret = nil;
  switch (ch) {
  case 's': {
    ret = ReadString();
    break;
  }
  case 't': {
    ret = ReadString();
    _string_Table.add(ret);
    break;
  }
  case 'R': {
    ret = _string_Table.get(_stream->ReadInt());
    break;
  }
  }
  return ret;
}
PyString *BinaryFileParser::ReadBytecode() {
  assert(_stream->Read() == 's');
  return ReadString();
}
PyString *BinaryFileParser::ReadString() {
  auto len = _stream->ReadInt();
  char val[len];
  for (int i = 0; i < len; ++i) {
    val[i] = _stream->Read();
  }
  return new PyString(val, len);
}

ArrayList<PyObject *> *BinaryFileParser::ReadNames() {
  if (_stream->Peek() == '(') {
    return ReadTuples();
  }
  return nullptr;
}
ArrayList<PyObject *> *BinaryFileParser::ReadConsts() {
  if (_stream->Peek() == '(') {
    return ReadTuples();
  }
  return nullptr;
}
ArrayList<PyObject *> *BinaryFileParser::ReadVarNames() {
  if (_stream->Peek() == '(') {
    return ReadTuples();
  }
  return nullptr;
}
ArrayList<PyObject *> *BinaryFileParser::ReadCellVars() {
  if (_stream->Peek() == '(') {
    return ReadTuples();
  }
  return nullptr;
}
ArrayList<PyObject *> *BinaryFileParser::ReadFreeVars() {
  if (_stream->Peek() == '(') {
    return ReadTuples();
  }
  return nullptr;
}
ArrayList<PyObject *> *BinaryFileParser::ReadTuples() {
  char obj_type = _stream->Read();
  assert(obj_type == '(');
  int length = _stream->ReadInt();
  ArrayList<PyObject *> *list = new ArrayList<PyObject *>(length);
  for (int i = 0; i < length; ++i) {
    obj_type = _stream->Read();
    switch (obj_type) {
    case 'c': {
      CodeObject *py_code = ReadCode();
      list->add(py_code);
      break;
    }
    case 'i': {
      PyInt *py_int = new PyInt(_stream->ReadInt());
      list->add(py_int);
      break;
    }
    case 'g': {
      PyFloat *py_float = new PyFloat(_stream->ReadFloat());
      list->add(py_float);
      break;
    }
    case 'N': {
      list->add(Universe::pyNone);
      break;
    }
    case 't': {
      PyString *str = ReadString();
      list->add(str);
      _string_Table.add(str);
      break;
    }
    case 's': {
      list->add(ReadString());
      break;
    }
    case 'R': {
      list->add(_string_Table.get(_stream->ReadInt()));
      break;
    }
    case '(': {
      list->add(new PyList(ReadTuples()));
      break;
    }
    default: {
      break;
    }
    }
  }
  return list;
}

} // namespace pvm