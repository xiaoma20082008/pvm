//
// Created by chunxiao ma on 2021/11/3.
//

#include "object/pyObject.hh"

#include "memory/gc.hh"
#include "memory/heap.hh"
#include "runtime/universe.hh"

namespace pvm {

ObjectKlass *ObjectKlass::GetInstance() {
  static ObjectKlass klass{};
  return &klass;
}
size_t ObjectKlass::Size() { return sizeof(PyObject); }
long PyObject::GetMarkWord() const { return _mark_word; }
Klass *PyObject::GetKlass() const { return _klass; }
PyDict *PyObject::GetDict() const { return _dict; }
void PyObject::SetMarkWord(long mark_word) { _mark_word = mark_word; }
void PyObject::SetKlass(Klass *klass) { _klass = klass; }
void PyObject::SetDict(PyDict *dict) { _dict = dict; }

PyObject *PyObject::ge(PyObject *x) { return GetKlass()->ge(this, x); }
PyObject *PyObject::gt(PyObject *x) { return GetKlass()->gt(this, x); }
PyObject *PyObject::le(PyObject *x) { return GetKlass()->le(this, x); }
PyObject *PyObject::lt(PyObject *x) { return GetKlass()->lt(this, x); }
PyObject *PyObject::ne(PyObject *x) { return GetKlass()->ne(this, x); }
PyObject *PyObject::eq(PyObject *x) { return GetKlass()->eq(this, x); }

PyObject *PyObject::add(PyObject *x) { return GetKlass()->add(this, x); }
PyObject *PyObject::sub(PyObject *x) { return GetKlass()->sub(this, x); }
PyObject *PyObject::mul(PyObject *x) { return GetKlass()->mul(this, x); }
PyObject *PyObject::div(PyObject *x) { return GetKlass()->div(this, x); }
PyObject *PyObject::mod(PyObject *x) { return GetKlass()->mod(this, x); }

PyObject *PyObject::subscr(PyObject *rhs) { return GetKlass()->subscr(this, rhs); }
void PyObject::store_subscr(PyObject *x, PyObject *y) { GetKlass()->store_subscr(this, x, y); }
void PyObject::del_subscr(PyObject *rhs) { GetKlass()->del_subscr(this, rhs); }

PyObject *PyObject::len() { return GetKlass()->len(this); }
PyObject *PyObject::contains(PyObject *rhs) { return GetKlass()->contains(this, rhs); }
PyObject *PyObject::getattr(PyObject *rhs) { return GetKlass()->getattr(this, rhs); }
PyObject *PyObject::setattr(PyObject *x, PyObject *y) { return GetKlass()->setattr(this, x, y); }
PyObject *PyObject::next() { return GetKlass()->next(this); }
PyObject *PyObject::iter() { return GetKlass()->iter(this); }
const char *PyObject::Type() { return GetKlass()->Type(); }
size_t PyObject::Size() { return GetKlass()->Size(); }
void PyObject::Accept(OopClosure *f) {
  f->Visit(_dict);
  GetKlass()->Accept(f, this);
}
void *PyObject::operator new(size_t size) { return Universe::_heap->Allocate(size); }

} // namespace pvm