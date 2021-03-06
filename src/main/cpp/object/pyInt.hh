//
// Created by chunxiao ma on 2021/11/4.
//

#ifndef PVM_PYINT_HH
#define PVM_PYINT_HH
#include "object/pyObject.hh"
namespace pvm {
class IntKlass : public Klass {
public:
  static IntKlass *GetInstance();

  PyObject *gt(PyObject *x, PyObject *y) override;
  PyObject *lt(PyObject *x, PyObject *y) override;
  PyObject *eq(PyObject *x, PyObject *y) override;
  PyObject *ne(PyObject *x, PyObject *y) override;
  PyObject *ge(PyObject *x, PyObject *y) override;
  PyObject *le(PyObject *x, PyObject *y) override;

  PyObject *add(PyObject *x, PyObject *y) override;
  PyObject *sub(PyObject *x, PyObject *y) override;
  PyObject *mul(PyObject *x, PyObject *y) override;
  PyObject *div(PyObject *x, PyObject *y) override;
  PyObject *mod(PyObject *x, PyObject *y) override;

  PyObject *allocate_instance(PyObject *callable, std::vector<PyObject *> args) override;
  size_t Size() override;
  void Accept(OopClosure *closure, PyObject *obj) override;
};

class PyInt : public PyPrimitiveObject {
public:
  explicit PyInt(int value);
  [[nodiscard]] int value() const;

private:
  const int _value{0};
};
} // namespace pvm
#endif // PVM_PYINT_HH
