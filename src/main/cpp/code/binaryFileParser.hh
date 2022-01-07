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
#include <vector>

namespace pvm {

class BinaryFileParser {
public:
  explicit BinaryFileParser(BufferedInputStream *stream);

  CodeObject *Parse();

  void Reset();

private:
  CodeObject *ReadCode();
  PyString *ReadFilename();
  PyString *ReadName();
  PyString *ReadBytecode();
  PyString *ReadString();
  std::vector<PyObject *> ReadConsts();
  std::vector<PyObject *> ReadNames();
  std::vector<PyObject *> ReadVarNames();
  std::vector<PyObject *> ReadCellVars();
  std::vector<PyObject *> ReadFreeVars();
  std::vector<PyObject *> ReadTuples();

private:
  BufferedInputStream *_stream{};
  std::vector<PyString *> _string_Table{};
};
} // namespace pvm
#endif // PVM_BINARY_FILE_PARSER_HH
