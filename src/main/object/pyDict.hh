//
// Created by chunxiao ma on 2021/11/4.
//

#ifndef PVM_PYDICT_HH
#define PVM_PYDICT_HH
#include "object/pyObject.hh"
#include "utils/map.hh"

namespace pvm {
class DictKlass : public Klass {
public:
  static DictKlass *get_instance();

  size_t size() override;
};
class PyDict : public PyObject {
public:
  PyDict();
  ~PyDict();
  void put(PyObject *k, PyObject *v);
  PyObject *get(PyObject *k);

private:
  Map<PyObject *, PyObject *> _map{};
};
} // namespace pvm
#endif // PVM_PYDICT_HH
