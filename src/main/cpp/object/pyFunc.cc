//
// Created by chunxiao ma on 2021/11/22.
//

#include "object/pyFunc.hh"
namespace pvm {

FuncKlass *FuncKlass::get_instance() {
  static FuncKlass klass{};
  return &klass;
}

size_t FuncKlass::Size() { return sizeof(PyFunc); }

NativeFuncKlass *NativeFuncKlass::get_instance() {
  static NativeFuncKlass klass{};
  return &klass;
}

MethodKlass *MethodKlass::get_instance() {
  static MethodKlass klass{};
  return &klass;
}

} // namespace pvm