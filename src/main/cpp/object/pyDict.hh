//
// Created by chunxiao ma on 2021/11/4.
//

#ifndef PVM_PYDICT_HH
#define PVM_PYDICT_HH
#include "object/pyObject.hh"
#include <unordered_map>

namespace pvm {
class DictKlass : public Klass {
public:
  static DictKlass *GetInstance();

  size_t Size() override;
};
class PyDict : public PyReferenceObject {
public:
  PyDict();
  ~PyDict();
  void Put(PyObject *k, PyObject *v);
  PyObject *Get(PyObject *k);
  bool Contains(PyObject *k);

private:
  std::unordered_map<PyObject *, PyObject *> _map{};
};
} // namespace pvm
#endif // PVM_PYDICT_HH
