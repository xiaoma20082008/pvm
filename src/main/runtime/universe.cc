//
// Created by chunxiao ma on 2021/11/3.
//

#include "runtime/universe.hh"

#include "code/codeObject.hh"
#include "memory/heap.hh"
#include "object/pyString.hh"

namespace pvm {

PyObject *Universe::pyTrue = nullptr;
PyObject *Universe::pyFalse = nullptr;
PyObject *Universe::pyNone = nullptr;
Heap *Universe::heap = nullptr;
CodeObject *Universe::code = nullptr;

void Universe::Genesis() {
  heap = Heap::GetInstance();
  pyTrue = new PyString("True");
  pyFalse = new PyString("False");
  pyNone = new PyString("None");
}

void Universe::Destroy() {}
} // namespace pvm