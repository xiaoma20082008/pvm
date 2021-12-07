//
// Created by chunxiao ma on 2021/11/3.
//

#ifndef PVM_INTERPRETER_HH
#define PVM_INTERPRETER_HH

namespace pvm {
class CodeObject;

class Interpreter {
public:
  static Interpreter *get_instance();
  Interpreter();
  ~Interpreter();

  Interpreter(const Interpreter &) = delete;
  Interpreter &operator=(const Interpreter &) = delete;
  Interpreter(Interpreter &&) = delete;
  Interpreter &operator=(Interpreter &&) = delete;

public:
  void run(CodeObject *codes);
};
} // namespace pvm
#endif // PVM_INTERPRETER_HH
