//
// Created by chunxiao ma on 2021/11/3.
//

#include "runtime/interpreter.hh"

#include "code/byteCode.hh"
#include "code/codeObject.hh"
#include "object/pyDict.hh"
#include "object/pyInt.hh"
#include "object/pyList.hh"
#include "object/pyModule.hh"
#include "object/pyString.hh"
#include "object/pyType.hh"
#include "runtime/frameObject.hh"
#include "runtime/stringTable.hh"
#include "runtime/universe.hh"
#include "utils/arrayList.hh"
namespace pvm {
#define POP() _frame->GetStack()->Pop()
#define PUSH(x) _frame->GetStack()->Push(x)
#define TOP() _frame->GetStack()->Top()

#define ST(x) StringTable::GetInstance()->STR(x)
#define STR(x) x##_str

Interpreter::Interpreter() {

  _builtins = new PyModule();
  _builtins->Put(new PyString("object"), ObjectKlass::GetInstance()->GetType());
  _builtins->Put(new PyString("True"), Universe::_py_true);
  _builtins->Put(new PyString("False"), Universe::_py_false);
  _builtins->Put(new PyString("None"), Universe::_py_none);

  //  _builtins->Put(new PyString("len"), new FunctionObject(len));
  //  _builtins->Put(new PyString("iter"), new FunctionObject(iter));
  //  _builtins->Put(new PyString("type"), new FunctionObject(type_of));
  //  _builtins->Put(new PyString("isinstance"), new FunctionObject(isinstance));
  //  _builtins->Put(new PyString("super"), new FunctionObject(builtin_super));
  //  _builtins->Put(new PyString("sysgc"), new FunctionObject(sysgc));

  _builtins->Put(new PyString("int"), IntKlass::GetInstance()->GetType());
  _builtins->Put(new PyString("object"), ObjectKlass::GetInstance()->GetType());
  _builtins->Put(new PyString("str"), StringKlass::GetInstance()->GetType());
  _builtins->Put(new PyString("list"), ListKlass::GetInstance()->GetType());
  _builtins->Put(new PyString("dict"), DictKlass::GetInstance()->GetType());
}

Interpreter::~Interpreter() = default;

Interpreter *Interpreter::GetInstance() {
  static Interpreter interpreter{};
  return &interpreter;
}

void Interpreter::Init() {
  _modules = new PyDict();
  _modules->Put(new PyString("__builtins__"), _builtins);
}

void Interpreter::Run(CodeObject *codes) {
  _frame = new FrameObject(codes);
  _frame->GetLocals()->Put(ST(name), new PyString("__main__"));
  EvalFrame();
  if (_status == Status::IS_EXCEPTION) {
  }
  DestroyFrame();
}

void Interpreter::EvalFrame() {
  PyObject *x{nullptr}, *y{nullptr}, *z{nullptr};
  while (_frame->HasNext()) {
    auto code = _frame->GetOpCode();
    bool has_args = (code & 0xFF) >= ByteCode::HAVE_ARGUMENT;
    int op_args = -1;
    if (has_args) {
      op_args = _frame->GetOpArgs();
    }
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
    case ByteCode::BUILD_TUPLE: {
      break;
    }
    case ByteCode::BUILD_LIST: {
      break;
    }
    case ByteCode::BUILD_SET: {
      break;
    }
    case ByteCode::BUILD_MAP: {
      x = new PyDict();
      PUSH(x);
      break;
    }
    default: {
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