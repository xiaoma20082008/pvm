//
// Created by chunxiao ma on 2021/11/4.
//

#include "object/pyType.hh"
namespace pvm {

PyType::PyType() = default;
Klass *PyType::owner_klass() { return _owner_klass; }
void PyType::set_owner_klass(Klass *klass) { _owner_klass = klass; }

} // namespace pvm