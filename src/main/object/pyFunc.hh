//
// Created by chunxiao ma on 2021/11/22.
//

#ifndef PVM_PYFUNC_HH
#define PVM_PYFUNC_HH
#include "object/pyObject.hh"
namespace pvm {

class FuncKlass : public Klass {
public:
  static FuncKlass *get_instance();

  size_t size() override;
};
class PyFunc : public PyObject {};

class NativeFuncKlass : public Klass {
  static NativeFuncKlass *get_instance();
};

class MethodKlass : public Klass {
  static MethodKlass *get_instance();
};
class PyMethod : public PyObject {};

} // namespace pvm
#endif // PVM_PYFUNC_HH
