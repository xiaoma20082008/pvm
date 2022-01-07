//
// Created by chunxiao ma on 2021/11/4.
//

#ifndef PVM_PYSTRING_HH
#define PVM_PYSTRING_HH
#include "object/pyObject.hh"
namespace pvm {
class StringKlass : public Klass {
public:
  StringKlass();
  static StringKlass *GetInstance();

  PyObject *add(PyObject *x, PyObject *y) override;
  PyObject *subscr(PyObject *x, PyObject *y) override;
  PyObject *contains(PyObject *x, PyObject *y) override;
  PyObject *len(PyObject *x) override;

  PyObject *allocate_instance(PyObject *callable, std::vector<PyObject *> args) override;
  size_t Size() override;
  void Accept(OopClosure *closure, PyObject *obj) override;
};

class PyString : public PyReferenceObject {
  friend class StringKlass;

public:
  PyString();
  explicit PyString(const char *value);
  explicit PyString(int length);
  PyString(const char *value, int length);

  [[nodiscard]] int Length() const;

  [[nodiscard]] char *Value() const;

private:
  void Set(int index, char ch);

private:
  char *_value{};
  int _length{0};
};
} // namespace pvm
#endif // PVM_PYSTRING_HH
