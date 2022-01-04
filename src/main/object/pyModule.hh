//
// Created by chunxiao ma on 2021/12/31.
//

#ifndef PVM_PYMODULE_HH
#define PVM_PYMODULE_HH
#include "object/pyObject.hh"
namespace pvm {
class ModuleKlass : public Klass {};

class PyModule : public PyObject {};
} // namespace pvm
#endif // PVM_PYMODULE_HH
