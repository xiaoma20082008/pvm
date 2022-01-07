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
PyObject *PyList::Pop() { return nil; }
PyObject *PyList::Top() { return nil; }
void PyList::Push(PyObject *o) {}
int PyList::size() { return _list.size(); }
} // namespace pvm