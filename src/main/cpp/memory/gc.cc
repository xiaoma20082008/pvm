//
// Created by chunxiao ma on 2022/1/4.
//

#include "gc.hh"
#include "memory/heap.hh"
#include "object/klass.hh"
#include "object/pyDict.hh"
#include "object/pyFloat.hh"
#include "object/pyInt.hh"
#include "object/pyList.hh"
#include "object/pyObject.hh"
#include "object/pyString.hh"
#include "runtime/frameObject.hh"
#include <iostream>
namespace pvm {
OopClosure::OopClosure(Space *from, Space *to, Space *metaspace) : _from(from), _to(to), _metaspace(metaspace) {}
OopClosure::~OopClosure() = default;
void OopClosure::Visit(Klass *obj) {}
void OopClosure::Visit(PyDict *obj) {}
void OopClosure::Visit(PyFloat *obj) {}
void OopClosure::Visit(PyFunc *obj) {}
void OopClosure::Visit(PyInt *obj) {}
void OopClosure::Visit(PyList *obj) {}
void OopClosure::Visit(PyString *obj) {}
void OopClosure::Visit(PyObject *obj) {}
void OopClosure::Visit(ArrayList<Block *> *obj) {}
void OopClosure::Visit(ArrayList<PyObject *> *obj) {}
void OopClosure::Visit(ArrayList<Klass *> *obj) {}
void OopClosure::Visit(Map<PyObject *, PyObject *> *obj) {}
void OopClosure::CMS() {
  // 1. mark
  // 2. swap

  std::cout << "mark" << std::endl;
  std::cout << "from:" << _from << "to  :" << _to << "meta:" << _metaspace << std::endl;
  std::cout << "swap" << std::endl;
}
} // namespace pvm