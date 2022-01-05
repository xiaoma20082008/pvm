//
// Created by chunxiao ma on 2021/11/4.
//

#ifndef PVM_PYTYPE_HH
#define PVM_PYTYPE_HH
#include "object/pyObject.hh"
namespace pvm {
class TypeKlass : public Klass {};

class PyType : public PyObject {
public:
  PyType();
  void set_owner_klass(Klass *klass);
  Klass *owner_klass();

private:
  Klass *_owner_klass{};
};
} // namespace pvm
#endif // PVM_PYTYPE_HH
