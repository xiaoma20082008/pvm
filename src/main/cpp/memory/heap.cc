//
// Created by chunxiao ma on 2021/11/3.
//

#include "memory/heap.hh"

#include "memory/gc.hh"
#include <cstdlib>
#include <iostream>

namespace pvm {

Space::Space(size_t size) {
  _size = size;
  _base = static_cast<char *>(std::malloc(_size));
  Clear();
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

bool Space::HasRemaining(size_t size) { return _capacity > size; }

bool Space::Contains(char *obj) { return false; }

void *Space::Alloc(size_t size) {
  char *start = _top;
  _top += size;
  _capacity -= size;
  return start;
}

size_t Space::Size() { return _size; }

void Space::Clear() {
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

Heap *Heap::GetInstance() {
  static Heap heap{MAX_CAP};
  return &heap;
}

void *Heap::Allocate(size_t size) {
  if (!_eden->HasRemaining(size)) {
    MinorGC();
  }
  if (!_eden->HasRemaining(size)) {
    MajorGC();
  }
  if (_eden->Size() >= size) {
    return _eden->Alloc(size);
  }
  return _heap->Alloc(size);
}

void *Heap::AllocateMeta(size_t size) {
  if (!_metaspace->HasRemaining(size)) {
    MajorGC();
  }
  return _metaspace->Alloc(size);
}

void Heap::GC() {
  MinorGC();
  MajorGC();
}

void Heap::MinorGC() {
  OopClosure closure{_survivor0, _survivor1, _metaspace};
  closure.CMS();
  _eden->Clear();
}

void Heap::MajorGC() {
  MinorGC();
}

} // namespace pvm