//
// Created by chunxiao ma on 2021/11/3.
//

#include "code/codeObject.hh"
namespace pvm {
CodeKlass::CodeKlass() = default;
CodeKlass *CodeKlass::get_instance() {
  static CodeKlass klass{};
  return &klass;
}
void CodeKlass::oops_do(OopClosure *closure, PyObject *obj) {}
size_t CodeKlass::size() { return sizeof(CodeObject); }

CodeObject::CodeObject(PyString *filename, PyString *name, int argc, int pos_argc, int kw_argc, int n_locals,
                       int stack_size, int flags, PyString *opcodes, ArrayList<PyObject *> *consts,
                       ArrayList<PyString *> *names, ArrayList<PyObject *> *var_names, ArrayList<PyObject *> *cell_vars,
                       ArrayList<PyObject *> *free_vars)
    : _filename(filename), _name(name), _argc(argc), _pos_argc(pos_argc), _kw_argc(kw_argc), _n_locals(n_locals),
      _stack_size(stack_size), _flags(flags), _opcodes(opcodes), _consts(consts), _names(names), _var_names(var_names),
      _cell_vars(cell_vars), _free_vars(free_vars) {
  set_klass(CodeKlass::get_instance());
}
} // namespace pvm