//
// Created by chunxiao ma on 2021/11/3.
//

#ifndef PVM_INTERPRETER_HH
#define PVM_INTERPRETER_HH
#include "code/byteCode.hh"
#include "code/codeObject.hh"
#include "utils/common.hh"

namespace pvm {
class CodeObject;
class FrameObject;
class PyDict;
class PyModule;

class Interpreter {
public:
  static Interpreter *GetInstance();
  Interpreter();
  ~Interpreter();

  __no_copy__(Interpreter);
  __no_move__(Interpreter);

public:
  void Init();
  void Run(CodeObject *codes);

  void EvalFrame();
  void EnterFrame(FrameObject *frame);
  void LeaveFrame();
  void DestroyFrame();

private:
  enum class Status {
    IS_OK,
    IS_BREAK,
    IS_CONTINUE,
    IS_EXCEPTION,
    IS_RETURN,
    IS_YIELD,
  };

private:
  PyModule *_builtins{};
  PyDict *_modules{};
  FrameObject *_frame{};
  PyObject *_ret_value{};

  //  PyObject *_exception_class{};
  //  PyObject *_pending_exception{};
  //  PyObject *_trace_back{};

  Status _status{};
};
} // namespace pvm
#endif // PVM_INTERPRETER_HH
