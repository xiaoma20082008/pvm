//
// Created by chunxiao ma on 2021/11/4.
//

#include "utils/map.hh"

#include "memory/heap.hh"
#include "runtime/universe.hh"

namespace pvm {

// region MapEntry

template <typename K, typename V> MapEntry<K, V>::MapEntry(const MapEntry<K, V> &entry) {
  _key = entry._key;
  _val = entry._val;
}

template <typename K, typename V> MapEntry<K, V>::MapEntry(K key, V val) {
  _key = key;
  _val = val;
}

template <typename K, typename V> MapEntry<K, V>::MapEntry() {
  _key = 0;
  _val = 0;
}

template <typename K, typename V> void *MapEntry<K, V>::operator new[](size_t size) {
  return Universe::heap->Allocate(size);
}

// endregion MapEntry

template <typename K, typename V> void *Map<K, V>::operator new[](size_t size) {
  return Universe::heap->Allocate(size);
}

template <typename K, typename V> V Map<K, V>::get(K key) {}

template <typename K, typename V> V Map<K, V>::remove(K key) {}

template <typename K, typename V> bool Map<K, V>::has_key(K key) { return false; }
} // namespace pvm