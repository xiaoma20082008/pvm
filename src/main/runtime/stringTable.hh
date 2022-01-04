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
  __no_move__(StringTable);
  __no_copy__(StringTable);

public:
  static StringTable *GetInstance();

  void Accept(OopClosure *f);

public:
  PyString *name_str;
};
} // namespace pvm
#endif // PVM_STRINGTABLE_HH
