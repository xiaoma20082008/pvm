//
// Created by chunxiao ma on 2021/12/31.
//

#include "stringTable.hh"
#include "memory/gc.hh"
#include "object/pyString.hh"
namespace pvm {
StringTable::StringTable() {
  next_str = new PyString("next");
  mod_str = new PyString("__module__");
  init_str = new PyString("__init__");
  add_str = new PyString("__add__");
  len_str = new PyString("__len__");
  call_str = new PyString("__call__");
  name_str = new PyString("__name__");
  iter_str = new PyString("__iter__");
  repr_str = new PyString("__repr__");
  getitem_str = new PyString("__getitem__");
  setitem_str = new PyString("__setitem__");
  getattr_str = new PyString("__getattr__");
  setattr_str = new PyString("__setattr__");

  so_pre_str = new PyString("lib");
  libdir_pre_str = new PyString("./lib/");
  empty_str = new PyString("");
  so_suf_str = new PyString(".so");
  pyc_suf_str = new PyString(".pyc");
}

StringTable *StringTable::GetInstance() {
  static StringTable table{};
  return &table;
}

void StringTable::Accept(OopClosure *f) { f->Visit(this); }

} // namespace pvm