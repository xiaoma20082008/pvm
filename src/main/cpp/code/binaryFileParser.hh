//
// Created by chunxiao ma on 2021/11/3.
//

#ifndef PVM_BINARY_FILE_PARSER_HH
#define PVM_BINARY_FILE_PARSER_HH

#include "code/codeObject.hh"
#include "object/pyDict.hh"
#include "object/pyFloat.hh"
#include "object/pyInt.hh"
#include "object/pyList.hh"
#include "object/pyObject.hh"
#include "object/pyString.hh"
#include "runtime/universe.hh"
#include "utils/arrayList.hh"
#include "utils/bufferedInputStream.hh"

namespace pvm {

class BinaryFileParser {
public:
  explicit BinaryFileParser(BufferedInputStream *stream);

  CodeObject *Parse();

private:
  CodeObject *ReadCode();
  PyString *ReadFilename();
  PyString *ReadName();
  PyString *ReadBytecode();
  PyString *ReadString();
  ArrayList<PyObject *> *ReadConsts();
  ArrayList<PyObject *> *ReadNames();
  ArrayList<PyObject *> *ReadVarNames();
  ArrayList<PyObject *> *ReadCellVars();
  ArrayList<PyObject *> *ReadFreeVars();
  ArrayList<PyObject *> *ReadTuples();

private:
  BufferedInputStream *_stream{};
  ArrayList<PyString *> _string_Table{};
};
} // namespace pvm
#endif // PVM_BINARY_FILE_PARSER_HH
