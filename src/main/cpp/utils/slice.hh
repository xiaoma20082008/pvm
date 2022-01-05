//
// Created by chunxiao ma on 2021/12/24.
//

#ifndef PVM_SLICE_HH
#define PVM_SLICE_HH
#pragma once

#include <cstddef>
#include <string>
namespace pvm {

class Slice {
public:
  Slice();
  Slice(const char *data);
  Slice(const char *data, size_t size);
  Slice(const std::string &data);

  ~Slice(); // destructor

  Slice(const Slice &);            // copy constructor
  Slice &operator=(const Slice &); // copy assignment

  Slice(Slice &&);            // move constructor
  Slice &operator=(Slice &&); // move assignment

  size_t Size() const;
  const char *Data() const;
  char operator[](size_t index) const;
  char CharAt(size_t index) const;
  bool Empty() const;
  bool StartsWith(const Slice &rhs) const;
  bool EndsWith(const Slice &rhs) const;
  int CompareTo(const Slice &rhs) const;
  std::string ToString() const;

private:
  const char *_data{};
  const size_t _size{};
};

inline bool operator>(const Slice &lhs, const Slice &rhs) { return lhs.CompareTo(rhs) > 0; }
inline bool operator<(const Slice &lhs, const Slice &rhs) { return lhs.CompareTo(rhs) < 0; }
inline bool operator>=(const Slice &lhs, const Slice &rhs) { return !(lhs < rhs); }
inline bool operator<=(const Slice &lhs, const Slice &rhs) { return !(lhs > rhs); }
inline bool operator==(const Slice &lhs, const Slice &rhs) { return lhs.CompareTo(rhs) == 0; }
inline bool operator!=(const Slice &lhs, const Slice &rhs) { return !(lhs == rhs); }

} // namespace pvm
#endif // PVM_SLICE_HH
