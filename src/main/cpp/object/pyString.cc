//
// Created by chunxiao ma on 2021/11/4.
//

#include "object/pyString.hh"

#include <string>

#include "memory/heap.hh"
#include "object/pyInt.hh"
#include "runtime/universe.hh"
namespace pvm {
StringKlass::StringKlass() = default;
StringKlass *StringKlass::GetInstance() {
  static StringKlass klass{};
  return &klass;
}

PyObject *StringKlass::add(PyObject *x, PyObject *y) {
  auto *lhs = static_cast<PyString *>(x);
  auto *rhs = static_cast<PyString *>(y);
  auto *res = new PyString(lhs->Length() + rhs->Length());
  memcpy(res->_value, lhs->_value, lhs->Length());
  memcpy(res->_value + lhs->Length(), rhs->_value, rhs->Length());
  res->Set(lhs->Length() + rhs->Length(), '\0');
  return res;
}
PyObject *StringKlass::subscr(PyObject *x, PyObject *y) {
  auto *lhs = static_cast<PyString *>(x);
  auto *rhs = static_cast<PyString *>(y);
  assert(lhs != nullptr);
  assert(rhs != nullptr);
  return nullptr;
}
PyObject *StringKlass::contains(PyObject *x, PyObject *y) {
  auto *lhs = static_cast<PyString *>(x);
  auto *rhs = static_cast<PyString *>(y);
  assert(lhs != nullptr);
  assert(rhs != nullptr);
  return nullptr;
}
PyObject *StringKlass::len(PyObject *x) {
  auto *lhs = static_cast<PyString *>(x);
  return new PyInt(lhs->Length());
}

PyObject *StringKlass::allocate_instance(PyObject *callable, std::vector<PyObject *> args) { return nullptr; }

void StringKlass::Accept(OopClosure *closure, PyObject *obj) {}

size_t StringKlass::Size() { return sizeof(PyString); }

PyString::PyString() : PyString("", 0) {}
PyString::PyString(const char *value) {
  _length = static_cast<int>(strlen(value));
  _value = static_cast<char *>(Universe::_heap->Allocate(_length));
  strcpy(_value, value);
  SetKlass(StringKlass::GetInstance());
}
PyString::PyString(int length) {
  _length = length;
  _value = static_cast<char *>(Universe::_heap->Allocate(_length));
  SetKlass(StringKlass::GetInstance());
}
PyString::PyString(const char *value, int length) {
  _length = length;
  _value = static_cast<char *>(Universe::_heap->Allocate(_length));
  // allow \0
  for (int i = 0; i < _length; ++i) {
    _value[i] = value[i];
  }
  SetKlass(StringKlass::GetInstance());
}
int PyString::Length() const { return _length; }
char *PyString::Value() const { return _value; }
void PyString::Set(int index, char ch) { _value[index] = ch; }
} // namespace pvm