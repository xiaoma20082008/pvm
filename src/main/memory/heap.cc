//
// Created by chunxiao ma on 2021/11/3.
//

#include "memory/heap.hh"

#include <cstdlib>
#include <iostream>

namespace pvm {

Space::Space(size_t size) {
  _size = size;
  _base = static_cast<char *>(std::malloc(_size));
  clear();
}

Space::~Space() {
  if (_base != nullptr) {
    std::free(_base);
    _base = nullptr;
  }
  _top = nullptr;
  _end = nullptr;
  _size = 0;
  _capacity = 0;
}

bool Space::can_alloc(size_t size) { return _capacity > size; }

bool Space::has_obj(char *obj) { return false; }

void *Space::alloc(size_t size) {
  char *start = _top;
  _top += size;
  _capacity -= size;
  return start;
}

size_t Space::size() { return _size; }

void Space::clear() {
  memset(_base, 0, _size);
  _end = _base + _size;
  _top = _base;
  // _top = (char *)(((long)(_base + 15)) & -16);
  _capacity = _end - _top;
}

size_t Heap::MAX_CAP = 8 * 1024 * 1024; // 8MB

Heap::Heap(size_t size) {
  // heap:metaspace:survivor1:survivor0:eden=32:16:1:1:8
  _eden = new Space(size);
  _survivor0 = new Space(size / 8);
  _survivor1 = new Space(size / 8);
  _metaspace = new Space(size * 2);
  _heap = new Space(size * 4);
  std::cout << "Heap\n";
}

Heap::~Heap() {
  if (_eden != nullptr) {
    delete _eden;
    _eden = nullptr;
  }
  if (_survivor0 != nullptr) {
    delete _survivor0;
    _survivor0 = nullptr;
  }
  if (_survivor1 != nullptr) {
    delete _survivor1;
    _survivor1 = nullptr;
  }
  if (_heap != nullptr) {
    delete _heap;
    _heap = nullptr;
  }
  if (_metaspace != nullptr) {
    delete _metaspace;
    _metaspace = nullptr;
  }
  std::cout << "~Heap\n";
}

Heap *Heap::get_instance() {
  static Heap heap{MAX_CAP};
  return &heap;
}

void *Heap::allocate(size_t size) {
  if (!_eden->can_alloc(size)) {
    minor_gc();
  }
  if (!_eden->can_alloc(size)) {
    major_gc();
  }
  if (_eden->size() >= size) {
    return _eden->alloc(size);
  }
  return _heap->alloc(size);
}

void *Heap::allocate_meta(size_t size) {
  if (!_metaspace->can_alloc(size)) {
    major_gc();
  }
  return _metaspace->alloc(size);
}

void Heap::gc() {
  minor_gc();
  major_gc();
}

void Heap::minor_gc() {
  std::cout << "minor_gc starting:\r\n";
  std::cout << "  before:\r\n";
  std::cout << "  after:\r\n";
  std::cout << "minor_gc finished\r\n";
  _eden->clear();
}

void Heap::major_gc() {
  std::cout << "major_gc starting:\r\n";
  std::cout << "  before:\r\n";
  std::cout << "  after:\r\n";
  std::cout << "major_gc finished\r\n";
  minor_gc();
}

} // namespace pvm