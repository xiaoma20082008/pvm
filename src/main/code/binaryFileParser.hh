//
// Created by chunxiao ma on 2021/11/3.
//

#ifndef PVM_BINARY_FILE_PARSER_HH
#define PVM_BINARY_FILE_PARSER_HH

namespace pvm {

class BufferedInputStream;
class CodeObject;
class PyString;
class PyObject;
template <typename T> class ArrayList;

class BinaryFileParser {
public:
  explicit BinaryFileParser(BufferedInputStream *stream);

  CodeObject *Parse();

private:
  CodeObject *ParseCode();

  PyString *read_filename();
  PyString *read_name();
  PyString *read_bytecode();
  PyString *read_string();

  ArrayList<PyObject *> *read_consts();
  ArrayList<PyObject *> *read_names();
  ArrayList<PyObject *> *read_var_names();
  ArrayList<PyObject *> *read_cell_vars();
  ArrayList<PyObject *> *read_free_vars();
  ArrayList<PyObject *> *read_tuples();

private:
  BufferedInputStream *_stream{};
};
} // namespace pvm
#endif // PVM_BINARY_FILE_PARSER_HH
