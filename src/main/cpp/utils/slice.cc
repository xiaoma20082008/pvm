//
// Created by chunxiao ma on 2021/12/24.
//

#include "slice.hh"
#include <cassert>
#include <cstring>

namespace pvm {

Slice::Slice() : Slice("", 0) {}
Slice::Slice(const char *data) : Slice(data, strlen(data)) {}
Slice::Slice(const std::string &data) : Slice(data.c_str(), data.length()) {}
Slice::Slice(const char *data, size_t size) : _data(data), _size(size) {}
Slice::~Slice() {}

Slice::Slice(const Slice &) = default;
Slice &Slice::operator=(const Slice &) { return *this; }
Slice::Slice(Slice &&) = default;
Slice &Slice::operator=(Slice &&) { return *this; }

char Slice::operator[](size_t index) const { return CharAt(index); }
char Slice::CharAt(size_t index) const {
  assert(index < Size());
  return _data[index];
}
size_t Slice::Size() const { return _size; }
const char *Slice::Data() const { return _data; }
bool Slice::Empty() const { return _size == 0; }
bool Slice::StartsWith(const Slice &rhs) const { return false; }
bool Slice::EndsWith(const Slice &rhs) const { return false; }
int Slice::CompareTo(const Slice &rhs) const {
  const size_t min_len = (_size < rhs._size) ? _size : rhs._size;
  int r = memcmp(_data, rhs._data, min_len);
  if (r == 0) {
    if (_size < rhs._size) {
      r = -1;
    } else if (_size > rhs._size) {
      r = +1;
    }
  }
  return r;
}
std::string Slice::ToString() const { return std::string{_data, _size}; }

} // namespace pvm