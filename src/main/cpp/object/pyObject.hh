//
// Created by chunxiao ma on 2021/11/3.
//

#ifndef PVM_PYOBJECT_HH
#define PVM_PYOBJECT_HH
#include "object/klass.hh"
namespace pvm {
class ObjectKlass : public Klass {
public:
  static ObjectKlass* GetInstance();
  virtual size_t Size();
};

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

  // region Getter/Setter

  void SetMarkWord(long mark_word);
  void SetKlass(Klass *klass);
  void SetDict(PyDict *dict);

  [[nodiscard]] long GetMarkWord() const;
  [[nodiscard]] Klass *GetKlass() const;
  [[nodiscard]] PyDict *GetDict() const;

  // endregion Getter/Setter

  // region typeof

  const char *Type();

  // endregion typeof
  // region sizeof

  size_t Size();

  // endregion sizeof

  void Accept(OopClosure *f);

  void *operator new(size_t size);

private:
  long _mark_word{0L};
  Klass *_klass{};
  PyDict *_dict{};
};

// reference type
class PyReferenceObject : public PyObject {};

// value type
class PyPrimitiveObject : public PyObject {};

} // namespace pvm
#endif // PVM_PYOBJECT_HH
