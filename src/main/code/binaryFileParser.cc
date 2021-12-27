//
// Created by chunxiao ma on 2021/11/3.
//

#include "code/binaryFileParser.hh"

#include <cassert>
#include <cstdio>

#include "code/codeObject.hh"
#include "object/pyString.hh"
#include "utils/arrayList.hh"
#include "utils/bufferedInputStream.hh"

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
  int magic_number = _stream->read_int();
  int mod_data = _stream->read_int();
  char object_type = _stream->read();
  printf("magic number= 0x%x\n", magic_number);
  printf("mod data    = 0x%x\n", mod_data);
  printf("object type = %c\n", object_type);
  CodeObject *codeObject = nullptr;
  if ('c' == object_type) {
    codeObject = ParseCode();
    printf("parse file  = done\n");
  } else {
  }
  return codeObject;
}

CodeObject *BinaryFileParser::ParseCode() {
  int argc = _stream->read_int();
  int n_locals = _stream->read_int();
  int stack_size = _stream->read_int();
  int flags = _stream->read_int();
  PyString *bytecode = read_bytecode();
  ArrayList<PyObject *> *consts = nullptr;
  ArrayList<PyString *> *names = nullptr;
  ArrayList<PyObject *> *var_names = nullptr;
  ArrayList<PyObject *> *free_vars = nullptr;
  ArrayList<PyObject *> *cell_vars = nullptr;

  PyString *filename = read_filename();
  PyString *name = read_name();
  printf("argc        = %d\n", argc);
  printf("n_locals    = %d\n", n_locals);
  printf("stack_size  = %d\n", stack_size);
  printf("flags       = %d\n", flags);
  printf("byte_codes  = %p\n", bytecode);
  return new CodeObject(filename, name, argc, 0, 0, n_locals, stack_size, flags, bytecode, consts, names, var_names,
                        cell_vars, free_vars);
}

PyString *BinaryFileParser::read_filename() { return nullptr; }
PyString *BinaryFileParser::read_name() { return nullptr; }
PyString *BinaryFileParser::read_bytecode() {
  assert(_stream->read() == 's');
  return read_string();
}

PyString *BinaryFileParser::read_string() {
  auto len = _stream->read_int();
  char val[len];
  for (int i = 0; i < len; ++i) {
    val[i] = _stream->read();
  }
  return new PyString(val, len);
}

ArrayList<PyObject *> *BinaryFileParser::read_names() { return nullptr; }
ArrayList<PyObject *> *BinaryFileParser::read_consts() { return nullptr; }
ArrayList<PyObject *> *BinaryFileParser::read_var_names() { return nullptr; }
ArrayList<PyObject *> *BinaryFileParser::read_cell_vars() { return nullptr; }
ArrayList<PyObject *> *BinaryFileParser::read_free_vars() { return nullptr; }
ArrayList<PyObject *> *BinaryFileParser::read_tuples() { return nullptr; }

} // namespace pvm