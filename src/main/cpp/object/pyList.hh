//
// Created by chunxiao ma on 2021/11/4.
//

#ifndef PVM_PYLIST_HH
#define PVM_PYLIST_HH
#include "object/pyObject.hh"
namespace pvm {
class ListKlass : public Klass {
public:
  static ListKlass *GetInstance();

  size_t Size() override;
};
class PyList : public PyReferenceObject {
public:
  PyList();
  PyList(std::vector<PyObject *> args);

  PyObject *Pop();
  PyObject *Top();
  void Push(PyObject *o);
  int size();

private:
  std::vector<PyObject *> _list{};
};
} // namespace pvm
#endif // PVM_PYLIST_HH
