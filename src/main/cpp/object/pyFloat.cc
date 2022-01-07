//
// Created by chunxiao ma on 2021/11/4.
//

#include "object/pyFloat.hh"

#include "runtime/universe.hh"

namespace pvm {

FloatKlass *FloatKlass::get_instance() {
  static FloatKlass klass{};
  return &klass;
}

size_t FloatKlass::Size() { return sizeof(PyFloat); }

PyObject *FloatKlass::ge(PyObject *x, PyObject *y) {
  auto *lhs = (PyFloat *)x;
  auto *rhs = (PyFloat *)y;
  return lhs->value() >= rhs->value() ? Universe::_py_true : Universe::_py_false;
}
PyObject *FloatKlass::gt(PyObject *x, PyObject *y) {
  auto *lhs = (PyFloat *)x;
  auto *rhs = (PyFloat *)y;
  return lhs->value() > rhs->value() ? Universe::_py_true : Universe::_py_false;
}
PyObject *FloatKlass::le(PyObject *x, PyObject *y) {
  auto *lhs = (PyFloat *)x;
  auto *rhs = (PyFloat *)y;
  return lhs->value() <= rhs->value() ? Universe::_py_true : Universe::_py_false;
}
PyObject *FloatKlass::lt(PyObject *x, PyObject *y) {
  auto *lhs = (PyFloat *)x;
  auto *rhs = (PyFloat *)y;
  return lhs->value() < rhs->value() ? Universe::_py_true : Universe::_py_false;
}
PyObject *FloatKlass::ne(PyObject *x, PyObject *y) {
  auto *lhs = (PyFloat *)x;
  auto *rhs = (PyFloat *)y;
  return lhs->value() != rhs->value() ? Universe::_py_true : Universe::_py_false;
}
PyObject *FloatKlass::eq(PyObject *x, PyObject *y) {
  auto *lhs = (PyFloat *)x;
  auto *rhs = (PyFloat *)y;
  return lhs->value() == rhs->value() ? Universe::_py_true : Universe::_py_false;
}

PyObject *FloatKlass::add(PyObject *x, PyObject *y) {
  auto *lhs = (PyFloat *)x;
  auto *rhs = (PyFloat *)y;
  return new PyFloat(lhs->value() + rhs->value());
}
PyObject *FloatKlass::sub(PyObject *x, PyObject *y) {
  auto *lhs = (PyFloat *)x;
  auto *rhs = (PyFloat *)y;
  return new PyFloat(lhs->value() - rhs->value());
}
PyObject *FloatKlass::mul(PyObject *x, PyObject *y) {
  auto *lhs = (PyFloat *)x;
  auto *rhs = (PyFloat *)y;
  return new PyFloat(lhs->value() * rhs->value());
}
PyObject *FloatKlass::div(PyObject *x, PyObject *y) {
  auto *lhs = (PyFloat *)x;
  auto *rhs = (PyFloat *)y;
  return new PyFloat(lhs->value() / rhs->value());
}

PyFloat::PyFloat(double value) : _value(value) { SetKlass(FloatKlass::get_instance()); }
double PyFloat::value() const { return _value; }

} // namespace pvm