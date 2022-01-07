//
// Created by chunxiao ma on 2021/12/31.
//

#include "pyModule.hh"
#include "memory/gc.hh"
#include "object/pyDict.hh"

namespace pvm {
ModuleKlass *ModuleKlass::GetInstance() {
  static ModuleKlass klass{};
  return &klass;
}

size_t ModuleKlass::Size() { return sizeof(PyModule); }
void ModuleKlass::Accept(OopClosure *f, PyObject *obj) { f->Visit(obj); }

PyModule::PyModule() : PyModule(new PyDict()) {}
PyModule::PyModule(PyDict *dict) : _dict(dict) { SetKlass(ModuleKlass::GetInstance()); }
PyModule::~PyModule() {}

void PyModule::Put(PyObject *k, PyObject *v) { _dict->Put(k, v); }
PyObject *PyModule::Get(PyObject *k) { return _dict->Get(k); }

} // namespace pvm