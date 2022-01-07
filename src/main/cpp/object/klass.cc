//
// Created by chunxiao ma on 2021/11/3.
//

#include "object/klass.hh"

#include "memory/heap.hh"
#include "object/pyList.hh"
#include "object/pyType.hh"
#include "runtime/universe.hh"
namespace pvm {

// region constructor

Klass::Klass() {}

// endregion constructor

// region static

PyObject *Klass::CreateKlass(PyObject *x, PyObject *super, PyString *name) {
  Klass *klass = new Klass();
  PyType *pt = new PyType();
  pt->set_owner_klass(klass);
  return pt;
}

int Klass::CompareKlass(Klass *lhs, Klass *rhs) {
  if (lhs == rhs) {
    return 0;
  }
  return 0;
}

// endregion static

// region Equals/HashCode

bool Klass::Equals(PyObject *x, PyObject *y) { return false; }
int Klass::HashCode(PyObject *x) { return 0; }

// endregion Equals/HashCode

// region getter/setter

PyList *Klass::GetSuper() { return _super; }
PyList *Klass::GetMro() { return _mro; }
PyType *Klass::GetType() { return _type; }
PyString *Klass::GetName() { return _name; }
PyDict *Klass::GetDict() { return _dict; }
void Klass::AddSuper(Klass *obj) {
  if (_super == nil) {
    _super = new PyList();
  }
  _super->Push(obj->GetType());
}
void Klass::SetSuper(PyList *super) { _super = super; }
void Klass::SetMro(PyList *mro) { _mro = mro; }
void Klass::SetType(PyType *type) { _type = type; }
void Klass::SetName(PyString *name) { _name = name; }
void Klass::SetDict(PyDict *dict) { _dict = dict; }

// endregion getter/setter

// region Operator Overload

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

// endregion Operator Overload

PyObject *Klass::subscr(PyObject *x, PyObject *y) { return nullptr; }
void Klass::store_subscr(PyObject *x, PyObject *y, PyObject *z) {}
PyObject *Klass::len(PyObject *x) { return nullptr; }
PyObject *Klass::contains(PyObject *x, PyObject *y) { return nullptr; }
PyObject *Klass::getattr(PyObject *x, PyObject *y) { return nullptr; }
PyObject *Klass::setattr(PyObject *x, PyObject *y, PyObject *z) { return nullptr; }
PyObject *Klass::next(PyObject *x) { return nullptr; }
PyObject *Klass::iter(PyObject *x) { return nullptr; }
PyObject *Klass::allocate_instance(PyObject *callable, std::vector<PyObject *> args) { return nullptr; }
PyObject *Klass::get_klass_attr(PyObject *x, PyObject *y) { return nullptr; }

void *Klass::operator new(size_t size) { return Universe::_heap->AllocateMeta(size); }

void Klass::Accept(OopClosure *closure) {}
void Klass::Accept(OopClosure *closure, PyObject *obj) {}

size_t Klass::Size() { return 0; }
const char *Klass::Type() { return "class"; }

PyObject *Klass::find_and_call(PyObject *x, std::vector<PyObject *> args, PyObject *func_name) { return nullptr; }

PyObject *Klass::find_in_parents(PyObject *x, PyObject *y) { return nullptr; }

} // namespace pvm