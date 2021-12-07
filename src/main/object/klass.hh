//
// Created by chunxiao ma on 2021/11/3.
//

#ifndef PVM_KLASS_HH
#define PVM_KLASS_HH
#include <cstddef>

#include "utils/arrayList.hh"

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

  static PyObject *create_klass(PyObject *x, PyObject *super, PyString *name);
  static int compare_klass(Klass *lhs, Klass *rhs);

  void set_super(PyList *super);
  void set_mro(PyList *mro);
  void set_type(PyType *type);
  void set_name(PyString *name);
  void set_dict(PyDict *dict);
  PyString *name();
  PyList *super();
  PyList *mro();
  PyType *type();
  PyDict *dict();

  // region operator overload

  virtual PyObject *gt(PyObject *x, PyObject *y);
  virtual PyObject *lt(PyObject *x, PyObject *y);
  virtual PyObject *eq(PyObject *x, PyObject *y);
  virtual PyObject *ne(PyObject *x, PyObject *y);
  virtual PyObject *ge(PyObject *x, PyObject *y);
  virtual PyObject *le(PyObject *x, PyObject *y);

  virtual PyObject *add(PyObject *x, PyObject *y); /* Addition */
  virtual PyObject *sub(PyObject *x, PyObject *y); /* Subtraction */
  virtual PyObject *mul(PyObject *x, PyObject *y); /* Multiplication*/
  virtual PyObject *div(PyObject *x, PyObject *y); /* div*/
  virtual PyObject *mod(PyObject *x, PyObject *y); /* */

  virtual PyObject *getattr(PyObject *x, PyObject *y);
  virtual PyObject *setattr(PyObject *x, PyObject *y, PyObject *z);

  // endregion operator overload

  virtual PyObject *subscr(PyObject *x, PyObject *y);
  virtual void store_subscr(PyObject *x, PyObject *y, PyObject *z);
  virtual void del_subscr(PyObject *x, PyObject *y) {}

  virtual PyObject *len(PyObject *x);

  virtual PyObject *contains(PyObject *x, PyObject *y);

  virtual PyObject *next(PyObject *x);
  virtual PyObject *iter(PyObject *x);

  virtual PyObject *allocate_instance(PyObject *callable, ArrayList<PyObject *> *args);
  virtual PyObject *get_klass_attr(PyObject *x, PyObject *y);

  void *operator new(size_t size);

  virtual size_t size();

  // gc interfaces
  virtual void oops_do(OopClosure *closure, PyObject *obj); // this is for objects of this type.
  virtual void oops_do(OopClosure *closure);                // for klass itself only.

private:
  PyObject *find_and_call(PyObject *x, ObjList args, PyObject *func_name);
  PyObject *find_in_parents(PyObject *x, PyObject *y);

private:
  PyList *_super{};  /* Super classes*/
  PyList *_mro{};    /* Method Resolution Order, Class search path*/
  PyType *_type{};   /**/
  PyString *_name{}; /**/
  PyDict *_dict{};   /**/
};

} // namespace pvm
#endif // PVM_KLASS_HH
