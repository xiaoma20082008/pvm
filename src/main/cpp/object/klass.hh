//
// Created by chunxiao ma on 2021/11/3.
//

#ifndef PVM_KLASS_HH
#define PVM_KLASS_HH
#include <cstddef>
#include <vector>

#include "utils/common.hh"

namespace pvm {

class PyType;
class PyObject;
class PyString;
class PyDict;
class PyList;
class OopClosure;

class Klass {
public:
  Klass();
  virtual ~Klass() {}

  static PyObject *CreateKlass(PyObject *x, PyObject *super, PyString *name);
  static int CompareKlass(Klass *lhs, Klass *rhs);

  // region Equals/HashCode

  virtual bool Equals(PyObject *x, PyObject *y);

  virtual int HashCode(PyObject *x);

  // endregion Equals/HashCode

  void AddSuper(Klass *obj);
  // region Getter/Setter

  void SetSuper(PyList *super);
  void SetMro(PyList *mro);
  void SetType(PyType *type);
  void SetName(PyString *name);
  void SetDict(PyDict *dict);
  PyString *GetName();
  PyList *GetSuper();
  PyList *GetMro();
  PyType *GetType();
  PyDict *GetDict();

  // endregion Getter/Setter

  // region Operator Overload

  virtual PyObject *gt(PyObject *x, PyObject *y);
  virtual PyObject *lt(PyObject *x, PyObject *y);
  virtual PyObject *eq(PyObject *x, PyObject *y);
  virtual PyObject *ne(PyObject *x, PyObject *y);
  virtual PyObject *ge(PyObject *x, PyObject *y);
  virtual PyObject *le(PyObject *x, PyObject *y);

  virtual PyObject *add(PyObject *x, PyObject *y); /* Addition */
  virtual PyObject *sub(PyObject *x, PyObject *y); /* Subtraction */
  virtual PyObject *mul(PyObject *x, PyObject *y); /* Multiplication */
  virtual PyObject *div(PyObject *x, PyObject *y); /* Division */
  virtual PyObject *mod(PyObject *x, PyObject *y); /* Modular */

  // endregion Operator Overload

  virtual PyObject *getattr(PyObject *x, PyObject *y);
  virtual PyObject *setattr(PyObject *x, PyObject *y, PyObject *z);

  virtual PyObject *subscr(PyObject *x, PyObject *y);
  virtual void store_subscr(PyObject *x, PyObject *y, PyObject *z);
  virtual void del_subscr(PyObject *x, PyObject *y) {}

  virtual PyObject *len(PyObject *x);

  virtual PyObject *contains(PyObject *x, PyObject *y);

  virtual PyObject *next(PyObject *x);
  virtual PyObject *iter(PyObject *x);

  virtual PyObject *allocate_instance(PyObject *callable, std::vector<PyObject *> args);
  virtual PyObject *get_klass_attr(PyObject *x, PyObject *y);

  void *operator new(size_t size);

  virtual size_t Size();
  virtual const char *Type();

  // gc interfaces
  virtual void Accept(OopClosure *closure, PyObject *obj); // this is for objects of this type.
  virtual void Accept(OopClosure *closure);                // for klass itself only.

private:
  PyObject *find_and_call(PyObject *x, std::vector<PyObject *> args, PyObject *func_name);
  PyObject *find_in_parents(PyObject *x, PyObject *y);

private:
  PyList *_super{};  /* Super classes*/
  PyList *_mro{};    /* Method Resolution Order, Class search path*/
  PyType *_type{};   /* Type Object */
  PyString *_name{}; /**/
  PyDict *_dict{};   /**/
};

} // namespace pvm
#endif // PVM_KLASS_HH
