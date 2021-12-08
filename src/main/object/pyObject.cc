//
// Created by chunxiao ma on 2021/11/3.
//

#include "object/pyObject.hh"

#include "memory/heap.hh"
#include "runtime/universe.hh"
namespace pvm {
long PyObject::mark_word() const { return _mark_word; }
Klass *PyObject::klass() const { return _klass; }
PyDict *PyObject::dict() const { return _dict; }
void PyObject::set_mark_word(long mark_word) { _mark_word = mark_word; }
void PyObject::set_klass(Klass *klass) { _klass = klass; }
void PyObject::set_dict(PyDict *dict) { _dict = dict; }

PyObject *PyObject::ge(PyObject *x) { return klass()->ge(this, x); }
PyObject *PyObject::gt(PyObject *x) { return klass()->gt(this, x); }
PyObject *PyObject::le(PyObject *x) { return klass()->le(this, x); }
PyObject *PyObject::lt(PyObject *x) { return klass()->lt(this, x); }
PyObject *PyObject::ne(PyObject *x) { return klass()->ne(this, x); }
PyObject *PyObject::eq(PyObject *x) { return klass()->eq(this, x); }

PyObject *PyObject::add(PyObject *x) { return klass()->add(this, x); }
PyObject *PyObject::sub(PyObject *x) { return klass()->sub(this, x); }
PyObject *PyObject::mul(PyObject *x) { return klass()->mul(this, x); }
PyObject *PyObject::div(PyObject *x) { return klass()->div(this, x); }
PyObject *PyObject::mod(PyObject *x) { return klass()->mod(this, x); }

PyObject *PyObject::subscr(PyObject *rhs) { return klass()->subscr(this, rhs); }
void PyObject::store_subscr(PyObject *x, PyObject *y) { klass()->store_subscr(this, x, y); }
void PyObject::del_subscr(PyObject *rhs) { klass()->del_subscr(this, rhs); }

PyObject *PyObject::len() { return klass()->len(this); }
PyObject *PyObject::contains(PyObject *rhs) { return klass()->contains(this, rhs); }
PyObject *PyObject::getattr(PyObject *rhs) { return klass()->getattr(this, rhs); }
PyObject *PyObject::setattr(PyObject *x, PyObject *y) { return klass()->setattr(this, x, y); }
PyObject *PyObject::next() { return klass()->next(this); }
PyObject *PyObject::iter() { return klass()->iter(this); }

void *PyObject::operator new(size_t size) { return Universe::heap->Allocate(size); }

} // namespace pvm