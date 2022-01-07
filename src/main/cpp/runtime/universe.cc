//
// Created by chunxiao ma on 2021/11/3.
//

#include "runtime/universe.hh"

#include "code/codeObject.hh"
#include "memory/heap.hh"
#include "object/pyString.hh"
#include "runtime/interpreter.hh"
namespace pvm {

PyObject *Universe::_py_true = nullptr;
PyObject *Universe::_py_false = nullptr;
PyObject *Universe::_py_none = nullptr;
Heap *Universe::_heap = nullptr;
CodeObject *Universe::_main_code = nullptr;

void Universe::Genesis() {
  _heap = Heap::GetInstance();
  _py_true = new PyString("True");
  _py_false = new PyString("False");
  _py_none = new PyString("None");
  Interpreter::GetInstance()->Init();
}

void Universe::Destroy() {}
} // namespace pvm