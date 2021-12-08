//
// Created by chunxiao ma on 2021/11/3.
//

#include "object/klass.hh"

#include "memory/heap.hh"
#include "runtime/universe.hh"
namespace pvm {

// region constructor

Klass::Klass() {}

// endregion constructor

// region static

PyObject *Klass::create_klass(PyObject *x, PyObject *super, PyString *name) { return nullptr; }

int Klass::compare_klass(Klass *lhs, Klass *rhs) {
  if (lhs == rhs) {
    return 0;
  }
  return 0;
}

// endregion static

// region getter/setter

PyList *Klass::super() { return _super; }
PyList *Klass::mro() { return _mro; }
PyType *Klass::type() { return _type; }
PyString *Klass::name() { return _name; }
PyDict *Klass::dict() { return _dict; }

void Klass::set_super(PyList *super) { _super = super; }
void Klass::set_mro(PyList *mro) { _mro = mro; }
void Klass::set_type(PyType *type) { _type = type; }
void Klass::set_name(PyString *name) { _name = name; }
void Klass::set_dict(PyDict *dict) { _dict = dict; }

// endregion getter/setter

// region virtual

PyObject *Klass::gt(PyObject *x, PyObject *y) { return nullptr; }
PyObject *Klass::ge(PyObject *x, PyObject *y) { return nullptr; }
PyObject *Klass::lt(PyObject *x, PyObject *y) { return nullptr; }
PyObject *Klass::le(PyObject *x, PyObject *y) { return nullptr; }
PyObject *Klass::eq(PyObject *x, PyObject *y) { return nullptr; }
PyObject *Klass::ne(PyObject *x, PyObject *y) { return nullptr; }

PyObject *Klass::add(PyObject *x, PyObject *y) { return nullptr; }
PyObject *Klass::sub(PyObject *x, PyObject *y) { return nullptr; }
PyObject *Klass::mul(PyObject *x, PyObject *y) { return nullptr; }
PyObject *Klass::div(PyObject *x, PyObject *y) { return nullptr; }
PyObject *Klass::mod(PyObject *x, PyObject *y) { return nullptr; }

PyObject *Klass::subscr(PyObject *x, PyObject *y) { return nullptr; }
void Klass::store_subscr(PyObject *x, PyObject *y, PyObject *z) {}
PyObject *Klass::len(PyObject *x) { return nullptr; }
PyObject *Klass::contains(PyObject *x, PyObject *y) { return nullptr; }
PyObject *Klass::getattr(PyObject *x, PyObject *y) { return nullptr; }
PyObject *Klass::setattr(PyObject *x, PyObject *y, PyObject *z) { return nullptr; }
PyObject *Klass::next(PyObject *x) { return nullptr; }
PyObject *Klass::iter(PyObject *x) { return nullptr; }
PyObject *Klass::allocate_instance(PyObject *callable, ArrayList<PyObject *> *args) { return nullptr; }
PyObject *Klass::get_klass_attr(PyObject *x, PyObject *y) { return nullptr; }

void *Klass::operator new(size_t size) { return Universe::heap->Allocate(size); }

void Klass::oops_do(OopClosure *closure) {}
void Klass::oops_do(OopClosure *closure, PyObject *obj) {}

size_t Klass::size() { return 0; }

PyObject *Klass::find_and_call(PyObject *x, ObjList args, PyObject *func_name) { return nullptr; }

PyObject *Klass::find_in_parents(PyObject *x, PyObject *y) { return nullptr; }
// endregion virtual

} // namespace pvm