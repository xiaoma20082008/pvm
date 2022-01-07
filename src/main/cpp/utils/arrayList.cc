//
// Created by chunxiao ma on 2021/11/3.
//

#include "utils/arrayList.hh"

#include "memory/heap.hh"
#include "runtime/universe.hh"
#include <new>

namespace pvm {
template <typename T> ArrayList<T>::ArrayList(int capacity) {
  _length = capacity;
  _size = 0;
  void *tmp = Universe::_heap->Allocate(sizeof(T) * capacity);
  _array = new (tmp) T[capacity];
}
template <typename T> void ArrayList<T>::add(T t) {
  if (_size >= _length) {
    expand();
  }
  _array[_size++] = t;
}

template <typename T> void ArrayList<T>::insert(int index, T t) { _array[index] = t; }

template <typename T> T ArrayList<T>::get(int index) { return _array[index]; }

template <typename T> void ArrayList<T>::set(int index, T t) {}
template <typename T> bool ArrayList<T>::contains(T t) {
  bool ret = false;
  for (int i = 0; i < _size; ++i) {
    if (_array[i] == t) {
      ret = true;
      break;
    }
  }
  return ret;
}

template <typename T> int ArrayList<T>::size() { return _size; }

template <typename T> int ArrayList<T>::length() { return _length; }

template <typename T> int ArrayList<T>::index(T t) { return 0; }
template <typename T> T *ArrayList<T>::value() { return _array; }
template <typename T> T ArrayList<T>::pop() { return _array[_size - 1]; }
template <typename T> void ArrayList<T>::remove_at(int index) {}
template <typename T> void ArrayList<T>::oops_do(OopClosure *closure) {}
template <typename T> void *ArrayList<T>::operator new(size_t size) { return Universe::_heap->Allocate(size); }

template <typename T> void ArrayList<T>::expand() {}

class PyObject;
class PyString;
class Block;

template class ArrayList<PyObject *>;
template class ArrayList<PyString *>;
template class ArrayList<Block *>;

} // namespace pvm