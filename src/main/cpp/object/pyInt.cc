//
// Created by chunxiao ma on 2021/11/4.
//

#include "object/pyInt.hh"

#include <cassert>

#include "runtime/universe.hh"
namespace pvm {

IntKlass *IntKlass::get_instance() {
  static IntKlass ik{};
  return &ik;
}

PyObject *IntKlass::ge(PyObject *x, PyObject *y) {
  auto *lhs = (PyInt *)x;
  auto *rhs = (PyInt *)y;
  return lhs->value() >= rhs->value() ? Universe::pyTrue : Universe::pyFalse;
}
PyObject *IntKlass::gt(PyObject *x, PyObject *y) {
  auto *lhs = (PyInt *)x;
  auto *rhs = (PyInt *)y;
  return lhs->value() > rhs->value() ? Universe::pyTrue : Universe::pyFalse;
}
PyObject *IntKlass::le(PyObject *x, PyObject *y) {
  auto *lhs = (PyInt *)x;
  auto *rhs = (PyInt *)y;
  return lhs->value() <= rhs->value() ? Universe::pyTrue : Universe::pyFalse;
}
PyObject *IntKlass::lt(PyObject *x, PyObject *y) {
  auto *lhs = (PyInt *)x;
  auto *rhs = (PyInt *)y;
  return lhs->value() < rhs->value() ? Universe::pyTrue : Universe::pyFalse;
}
PyObject *IntKlass::ne(PyObject *x, PyObject *y) {
  auto *lhs = (PyInt *)x;
  auto *rhs = (PyInt *)y;
  return lhs->value() != rhs->value() ? Universe::pyTrue : Universe::pyFalse;
}
PyObject *IntKlass::eq(PyObject *x, PyObject *y) {
  auto *lhs = (PyInt *)x;
  auto *rhs = (PyInt *)y;
  return lhs->value() == rhs->value() ? Universe::pyTrue : Universe::pyFalse;
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

PyObject *IntKlass::allocate_instance(PyObject *callable, ArrayList<PyObject *> *args) { return nullptr; }
size_t IntKlass::size() { return sizeof(PyInt); }
void IntKlass::Accept(OopClosure *closure, PyObject *obj) {}

PyInt::PyInt(int value) : _value(value) { set_klass(IntKlass::get_instance()); }
int PyInt::value() const { return _value; }
} // namespace pvm