//
// Created by chunxiao ma on 2021/11/4.
//

#include "object/pyInt.hh"

#include <cassert>

#include "runtime/universe.hh"
namespace pvm {

IntKlass *IntKlass::GetInstance() {
  static IntKlass ik{};
  return &ik;
}

PyObject *IntKlass::ge(PyObject *x, PyObject *y) {
  auto *lhs = (PyInt *)x;
  auto *rhs = (PyInt *)y;
  return lhs->value() >= rhs->value() ? Universe::_py_true : Universe::_py_false;
}
PyObject *IntKlass::gt(PyObject *x, PyObject *y) {
  auto *lhs = (PyInt *)x;
  auto *rhs = (PyInt *)y;
  return lhs->value() > rhs->value() ? Universe::_py_true : Universe::_py_false;
}
PyObject *IntKlass::le(PyObject *x, PyObject *y) {
  auto *lhs = (PyInt *)x;
  auto *rhs = (PyInt *)y;
  return lhs->value() <= rhs->value() ? Universe::_py_true : Universe::_py_false;
}
PyObject *IntKlass::lt(PyObject *x, PyObject *y) {
  auto *lhs = (PyInt *)x;
  auto *rhs = (PyInt *)y;
  return lhs->value() < rhs->value() ? Universe::_py_true : Universe::_py_false;
}
PyObject *IntKlass::ne(PyObject *x, PyObject *y) {
  auto *lhs = (PyInt *)x;
  auto *rhs = (PyInt *)y;
  return lhs->value() != rhs->value() ? Universe::_py_true : Universe::_py_false;
}
PyObject *IntKlass::eq(PyObject *x, PyObject *y) {
  auto *lhs = (PyInt *)x;
  auto *rhs = (PyInt *)y;
  return lhs->value() == rhs->value() ? Universe::_py_true : Universe::_py_false;
}

PyObject *IntKlass::add(PyObject *x, PyObject *y) {
  auto *lhs = (PyInt *)x;
  auto *rhs = (PyInt *)y;
  return new PyInt(lhs->value() + rhs->value());
}
PyObject *IntKlass::sub(PyObject *x, PyObject *y) {
  auto *lhs = (PyInt *)x;
  auto *rhs = (PyInt *)y;
  return new PyInt(lhs->value() - rhs->value());
}
PyObject *IntKlass::mul(PyObject *x, PyObject *y) {
  auto *lhs = (PyInt *)x;
  auto *rhs = (PyInt *)y;
  return new PyInt(lhs->value() * rhs->value());
}
PyObject *IntKlass::mod(PyObject *x, PyObject *y) {
  auto *lhs = (PyInt *)x;
  auto *rhs = (PyInt *)y;
  return new PyInt(lhs->value() % rhs->value());
}
PyObject *IntKlass::div(PyObject *x, PyObject *y) {
  auto *lhs = (PyInt *)x;
  auto *rhs = (PyInt *)y;
  return new PyInt(lhs->value() / rhs->value());
}

PyObject *IntKlass::allocate_instance(PyObject *callable, std::vector<PyObject *> args) { return nullptr; }
size_t IntKlass::Size() { return sizeof(PyInt); }
void IntKlass::Accept(OopClosure *closure, PyObject *obj) {}

PyInt::PyInt(int value) : _value(value) { SetKlass(IntKlass::GetInstance()); }
int PyInt::value() const { return _value; }
} // namespace pvm