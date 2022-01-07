//
// Created by chunxiao ma on 2021/11/3.
//

#include "code/codeObject.hh"
#include "object/pyString.hh"

namespace pvm {
CodeKlass::CodeKlass() {
  SetName(new PyString("code"));
  AddSuper(ObjectKlass::GetInstance());
}
CodeKlass *CodeKlass::GetInstance() {
  static CodeKlass klass{};
  return &klass;
}
void CodeKlass::Accept(OopClosure *closure, PyObject *obj) {}
size_t CodeKlass::Size() { return sizeof(CodeObject); }

CodeObject::CodeObject(PyString *filename, PyString *name, int argc, int pos_argc, int kw_argc, int n_locals,
                       int stack_size, int flags, PyString *opcodes, std::vector<PyObject *> consts,
                       std::vector<PyObject *> names, std::vector<PyObject *> var_names,
                       std::vector<PyObject *> cell_vars, std::vector<PyObject *> free_vars)
    : _filename(filename), _name(name), _argc(argc), _pos_argc(pos_argc), _kw_argc(kw_argc), _n_locals(n_locals),
      _stack_size(stack_size), _flags(flags), _opcodes(opcodes), _consts(consts), _names(names), _var_names(var_names),
      _cell_vars(cell_vars), _free_vars(free_vars) {
  SetKlass(CodeKlass::GetInstance());
}
//
//CodeObject::CodeObject(const CodeObject &rhs) {
//  if (&rhs != this) {
//    _filename = rhs._filename;
//    _name = rhs._name;
//    _argc = rhs._argc;
//    _pos_argc = rhs._pos_argc;
//    _kw_argc = rhs._kw_argc;
//    _n_locals = rhs._n_locals;
//    _stack_size = rhs._stack_size;
//    _flags = rhs._flags;
//    _opcodes = rhs._opcodes;
//    _consts = rhs._consts;
//    _names = rhs._names;
//    _var_names = rhs._var_names;
//    _cell_vars = rhs._cell_vars;
//    _free_vars = rhs._free_vars;
//  }
//}
//CodeObject &CodeObject::operator=(const CodeObject &rhs) {
//  _filename = rhs._filename;
//  _name = rhs._name;
//  _argc = rhs._argc;
//  _pos_argc = rhs._pos_argc;
//  _kw_argc = rhs._kw_argc;
//  _n_locals = rhs._n_locals;
//  _stack_size = rhs._stack_size;
//  _flags = rhs._flags;
//  _opcodes = rhs._opcodes;
//  _consts = rhs._consts;
//  _names = rhs._names;
//  _var_names = rhs._var_names;
//  _cell_vars = rhs._cell_vars;
//  _free_vars = rhs._free_vars;
//  return *this;
//}
//CodeObject::~CodeObject() = default;
} // namespace pvm