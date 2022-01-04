//
// Created by chunxiao ma on 2021/11/3.
//

#include "runtime/interpreter.hh"

#include "code/byteCode.hh"
#include "code/codeObject.hh"
#include "object/pyDict.hh"
#include "object/pyList.hh"
#include "object/pyModule.hh"
#include "object/pyString.hh"
#include "runtime/frameObject.hh"
#include "runtime/stringTable.hh"
#include "utils/arrayList.hh"

namespace pvm {
#define POP() _frame->GetStack()->Pop()
#define PUSH(x) _frame->GetStack()->Push(x)
#define TOP() _frame->GetStack()->Top()

#define ST(x) StringTable::GetInstance()->STR(x)
#define STR(x) x##_str

Interpreter::Interpreter() = default;
Interpreter::~Interpreter() = default;

Interpreter *Interpreter::GetInstance() {
  static Interpreter interpreter{};
  return &interpreter;
}

void Interpreter::Init() {}
void Interpreter::Run(CodeObject *codes) {
  _frame = new FrameObject(codes);
  _frame->GetLocals()->put(ST(name), new PyString("__main__"));
  EvalFrame();
  if (_status == Status::IS_EXCEPTION) {
  }
}

void Interpreter::EvalFrame() {
  PyObject *x, *y, *z;
  while (_frame->HasNext()) {
    auto code = _frame->GetOpCode();
    switch (code) {
    case ByteCode::POP_TOP: {
      POP();
      break;
    }
    case ByteCode::ROT_TWO: {
      x = POP();
      y = POP();
      PUSH(x);
      PUSH(y);
      break;
    }
    case ByteCode::ROT_THREE: {
      x = POP();
      y = POP();
      z = POP();
      PUSH(x);
      PUSH(y);
      PUSH(z);
      break;
    }
    case ByteCode::DUP_TOP: {
      PUSH(TOP());
      break;
    }
    case ByteCode::DUP_TOP_TWO: {
      x = POP();
      y = POP();
      PUSH(x);
      PUSH(y);
      break;
    }
    case ByteCode::ROT_FOUR: {
      x = POP();
      y = POP();
      z = POP();
      PUSH(x);
      PUSH(y);
      PUSH(z);
      break;
    }
    }
  }
}
void Interpreter::EnterFrame(FrameObject *frame) {
  frame->SetCaller(_frame);
  _frame = frame;
}
void Interpreter::LeaveFrame() {
  DestroyFrame();
  PUSH(_ret_value);
}
void Interpreter::DestroyFrame() {
  FrameObject *tmp = _frame;
  _frame = tmp->GetCaller();
  delete tmp;
}
} // namespace pvm