//
// Created by chunxiao ma on 2021/11/4.
//

#include "object/pyList.hh"

namespace pvm {
ListKlass *ListKlass::get_instance() {
  static ListKlass klass{};
  return &klass;
}

size_t ListKlass::size() { return sizeof(PyList); }

PyList::PyList() : _list(nullptr) {}
PyList::PyList(ObjList ol) : _list(ol) {}
PyObject *PyList::Pop() { return nil; }
PyObject *PyList::Top() { return nil; }
void PyList::Push(PyObject *o) {}
int PyList::Size() { return _list == nullptr ? 0 : _list->size(); }
} // namespace pvm