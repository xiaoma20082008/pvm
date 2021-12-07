//
// Created by chunxiao ma on 2021/11/3.
//

#ifndef PVM_ARRAYLIST_HH
#define PVM_ARRAYLIST_HH
#include <cstddef>
namespace pvm {
class OopClosure;
template <typename T> class ArrayList {
public:
  explicit ArrayList(int capacity = 8);

  void add(T t);

  void insert(int index, T t);

  T get(int index);

  void set(int index, T t);

  bool contains(T t);

  int size();

  int length();

  int index(T t);

  T *value();

  T pop();

  void remove_at(int index);

  void oops_do(OopClosure *closure);

  void *operator new(size_t size);

private:
  T *_array{nullptr};
  int _size{0};
  int _length{0};

  void expand();
};

class PyObject;
using ObjList = ArrayList<PyObject *> *;
} // namespace pvm
#endif // PVM_ARRAYLIST_HH
