//
// Created by chunxiao ma on 2021/11/4.
//

#ifndef PVM_MAP_HH
#define PVM_MAP_HH
#include <cstddef>

namespace pvm {

template <typename K, typename V> class MapEntry {
  MapEntry(const MapEntry<K, V> &entry);
  MapEntry(K k, V v);
  MapEntry();

  void *operator new[](size_t size);

public:
  K _key;
  V _val;
};

template <typename K, typename V> class Map {
public:
  V get(K key);
  V remove(K key);
  bool has_key(K key);

  void *operator new[](size_t size);

private:
  MapEntry<K, V> *_entries{nullptr};
  int _size{0};
  int _length{0};
};

} // namespace pvm
#endif // PVM_MAP_HH
