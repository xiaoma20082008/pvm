//
// Created by chunxiao ma on 2021/11/3.
//

#ifndef PVM_CODE_OBJECT_HH
#define PVM_CODE_OBJECT_HH
#include "object/pyObject.hh"
namespace pvm {

class PyString;
template <typename T> class ArrayList;

class CodeKlass : public Klass {
public:
  CodeKlass();
  static CodeKlass *GetInstance();
  size_t size() override;
  void Accept(OopClosure *closure, PyObject *obj) override;
};

/* https://github.com/python/cpython/blob/main/Include/cpython/code.h
 */
class CodeObject : public PyObject {
public:
  CodeObject(PyString *fn, PyString *name, int argc, int pos_argc, int kw_argc, int n_locals, int stack_size, int flags,
             PyString *opcodes, ArrayList<PyObject *> *consts, ArrayList<PyObject *> *names,
             ArrayList<PyObject *> *var_names, ArrayList<PyObject *> *cell_vars, ArrayList<PyObject *> *free_vars);

public:
  PyString *_filename{}; /* unicode (where it was loaded from) */
  PyString *_name{};     /* unicode (name, for reference) */
  int _argc{0};          /* arguments, except *args */
  int _pos_argc{0};      /* positional only arguments */
  int _kw_argc{0};       /* keyword only arguments */
  int _n_locals;         /* number of local variables */
  int _stack_size{0};    /* entries needed for evaluation stack */
  int _flags{0};         /* CO_...*/
  int _first_line_no{1}; /* first source line number */
  PyString *_opcodes{};  /* instruction opcodes */

  ArrayList<PyObject *> *_consts{};    /* list (constants used) */
  ArrayList<PyObject *> *_names{};     /* list of strings (names used) */
  ArrayList<PyObject *> *_var_names{}; /* tuple of strings (local variable names) */
  ArrayList<PyObject *> *_cell_vars{}; /* tuple of strings (cell variable names) */
  ArrayList<PyObject *> *_free_vars{}; /* tuple of strings (free variable names) */
};
} // namespace pvm
#endif // PVM_CODE_OBJECT_HH
