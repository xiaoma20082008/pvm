//
// Created by chunxiao ma on 2021/11/4.
//

#include "object/pyDict.hh"

namespace pvm {
DictKlass *DictKlass::GetInstance() {
  static DictKlass klass{};
  return &klass;
}

size_t DictKlass::Size() { return sizeof(PyDict); }
PyDict::PyDict() { SetKlass(DictKlass::GetInstance()); }
PyDict::~PyDict() = default;

PyObject *PyDict::Get(PyObject *k) {
  PyObject *ret = nil;
  auto it = _map.find(k);
  if (it != _map.end()) {
    ret = it->second;
  }
  return ret;
}
void PyDict::Put(PyObject *k, PyObject *v) { _map[k] = v; }
bool PyDict::Contains(PyObject *k) { return _map.find(k) != _map.end(); }

} // namespace pvm