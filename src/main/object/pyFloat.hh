//
// Created by chunxiao ma on 2021/11/4.
//

#ifndef PVM_PYFLOAT_HH
#define PVM_PYFLOAT_HH
#include "object/pyObject.hh"

namespace pvm {
class FloatKlass : public Klass {
public:
  static FloatKlass *get_instance();

  size_t size() override;

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
  // PyObject *mod(PyObject *x, PyObject *y) override;
};

class PyFloat : public PyObject {
public:
  explicit PyFloat(double value);
  [[nodiscard]] double value() const;

private:
  const double _value{0.0};
};
} // namespace pvm
#endif // PVM_PYFLOAT_HH
