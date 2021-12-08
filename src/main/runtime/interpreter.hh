//
// Created by chunxiao ma on 2021/11/3.
//

#ifndef PVM_INTERPRETER_HH
#define PVM_INTERPRETER_HH
#include "utils/common.hh"

namespace pvm {
class CodeObject;

class Interpreter {
public:
  static Interpreter *get_instance();
  Interpreter();
  ~Interpreter();

  __no_copy__(Interpreter);
  __no_move__(Interpreter);

public:
  void run(CodeObject *codes);
};
} // namespace pvm
#endif // PVM_INTERPRETER_HH
