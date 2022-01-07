//
// Created by chunxiao ma on 2021/12/31.
//

#ifndef PVM_STRINGTABLE_HH
#define PVM_STRINGTABLE_HH
#include "utils/common.hh"
namespace pvm {
class PyString;
class OopClosure;
class StringTable {
public:
  StringTable();
  __no_move__(StringTable);
  __no_copy__(StringTable);

public:
  static StringTable *GetInstance();

  void Accept(OopClosure *f);

public:
  PyString *next_str;
  PyString *mod_str;
  PyString *init_str;
  PyString *add_str;
  PyString *len_str;
  PyString *call_str;
  PyString *getitem_str;
  PyString *setitem_str;
  PyString *getattr_str;
  PyString *setattr_str;
  PyString *name_str;
  PyString *iter_str;
  PyString *repr_str;

  PyString *libdir_pre_str;
  PyString *empty_str;
  PyString *so_pre_str;
  PyString *so_suf_str;
  PyString *pyc_suf_str;
};
} // namespace pvm
#endif // PVM_STRINGTABLE_HH
