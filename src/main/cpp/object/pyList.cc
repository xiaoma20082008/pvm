//
// Created by chunxiao ma on 2021/11/4.
//

#include "object/pyList.hh"

namespace pvm {
ListKlass *ListKlass::GetInstance() {
  static ListKlass klass{};
  return &klass;
}

size_t ListKlass::Size() { return sizeof(PyList); }

PyList::PyList() {}
PyList::PyList(std::vector<PyObject *> args) : _list(args) {}
PyObject *PyList::Pop() {
  PyObject *x = _list.back();
  _list.pop_back();
  return x;
}
PyObject *PyList::Top() { return _list.back(); }
void PyList::Push(PyObject *o) { _list.push_back(o); }
int PyList::size() { return _list.size(); }
} // namespace pvm