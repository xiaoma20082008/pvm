//
// Created by chunxiao ma on 2021/11/4.
//

#include "object/pyList.hh"

namespace pvm {
ListKlass *ListKlass::get_instance() {
  static ListKlass klass{};
  return &klass;
}

size_t ListKlass::size() { return sizeof(PyList); }

} // namespace pvm