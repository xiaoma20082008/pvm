//
// Created by chunxiao ma on 2021/11/4.
//

#ifndef PVM_PYLIST_HH
#define PVM_PYLIST_HH
#include "object/pyObject.hh"
namespace pvm {
class ListKlass : public Klass {
public:
  static ListKlass *get_instance();

  size_t size() override;
};
class PyList : public PyObject {
public:
  PyList();
  PyList(ObjList ol);

  PyObject *Pop();
  PyObject *Top();
  void Push(PyObject *o);
  int Size();

private:
  ArrayList<PyObject *> *_list{};
};
} // namespace pvm
#endif // PVM_PYLIST_HH
