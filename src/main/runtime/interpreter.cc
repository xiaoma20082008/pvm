//
// Created by chunxiao ma on 2021/11/3.
//

#include "runtime/interpreter.hh"

#include "code/codeObject.hh"
#include "object/pyDict.hh"
#include "object/pyString.hh"
#include "runtime/frameObject.hh"
#include "utils/arrayList.hh"

namespace pvm {

Interpreter::Interpreter() = default;
Interpreter::~Interpreter() = default;

Interpreter *Interpreter::get_instance() {
  static Interpreter interpreter{};
  return &interpreter;
}

void Interpreter::run(CodeObject *codes) {}

} // namespace pvm