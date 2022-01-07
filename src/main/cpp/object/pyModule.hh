//
// Created by chunxiao ma on 2021/12/31.
//

#ifndef PVM_PYMODULE_HH
#define PVM_PYMODULE_HH
#include "object/pyObject.hh"
namespace pvm {
class PyDict;

class ModuleKlass : public Klass {
public:
  static ModuleKlass *GetInstance();
  virtual size_t Size() override;
  virtual void Accept(OopClosure *closure, PyObject *obj) override;
};

class PyModule : public PyReferenceObject {
public:
  PyModule();
  PyModule(PyDict *dict);
  ~PyModule();

public:
  void Put(PyObject *k, PyObject *v);
  PyObject *Get(PyObject *k);

private:
  PyDict *_dict{};
};
} // namespace pvm
#endif // PVM_PYMODULE_HH
