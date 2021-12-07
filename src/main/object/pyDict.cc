//
// Created by chunxiao ma on 2021/11/4.
//

#include "object/pyDict.hh"

namespace pvm {
DictKlass *DictKlass::get_instance() {
  static DictKlass klass{};
  return &klass;
}

size_t DictKlass::size() { return sizeof(PyDict); }
PyDict::PyDict() = default;
PyDict::~PyDict() = default;

PyObject *PyDict::get(PyObject *k) { return nullptr; }
void PyDict::put(PyObject *k, PyObject *v) {}

} // namespace pvm