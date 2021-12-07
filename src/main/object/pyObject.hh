//
// Created by chunxiao ma on 2021/11/3.
//

#ifndef PVM_PYOBJECT_HH
#define PVM_PYOBJECT_HH
#include "object/klass.hh"
namespace pvm {
class ObjectKlass : public Klass {};

class PyObject {
public:
  PyObject *gt(PyObject *rhs);
  PyObject *lt(PyObject *rhs);
  PyObject *eq(PyObject *rhs);
  PyObject *ne(PyObject *rhs);
  PyObject *ge(PyObject *rhs);
  PyObject *le(PyObject *rhs);

  PyObject *add(PyObject *rhs);
  PyObject *sub(PyObject *rhs);
  PyObject *mul(PyObject *rhs);
  PyObject *div(PyObject *rhs);
  PyObject *mod(PyObject *rhs);

  PyObject *getattr(PyObject *rhs);
  PyObject *setattr(PyObject *x, PyObject *y);

  PyObject *subscr(PyObject *rhs);
  void store_subscr(PyObject *x, PyObject *y);
  void del_subscr(PyObject *rhs);

  PyObject *len();
  PyObject *contains(PyObject *rhs);

  PyObject *next();
  PyObject *iter();

  void set_mark_word(long mark_word);
  void set_klass(Klass *klass);
  void set_dict(PyDict *dict);

  [[nodiscard]] long mark_word() const;
  [[nodiscard]] Klass *klass() const;
  [[nodiscard]] PyDict *dict() const;

  void *operator new(size_t size);

private:
  long _mark_word{0L};
  Klass *_klass{};
  PyDict *_dict{};
};

// reference type
class PyReferObject : public PyObject {};

// value type
class PyValueObject : public PyObject {};

} // namespace pvm
#endif // PVM_PYOBJECT_HH
