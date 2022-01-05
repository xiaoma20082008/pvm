//
// Created by chunxiao ma on 2021/12/31.
//

#include "stringTable.hh"
#include "memory/gc.hh"
namespace pvm {
StringTable *StringTable::GetInstance() {
  static StringTable table{};
  return &table;
}
void StringTable::Accept(OopClosure *f) {
}
} // namespace pvm