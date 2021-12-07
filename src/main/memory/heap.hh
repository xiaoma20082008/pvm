//
// Created by chunxiao ma on 2021/11/3.
//

#ifndef PVM_HEAP_HH
#define PVM_HEAP_HH
#include <cstddef>
namespace pvm {

class Space {
public:
  explicit Space(size_t size);
  ~Space();

public:
  bool can_alloc(size_t size);
  bool has_obj(char *obj);
  void *alloc(size_t size);
  size_t size();
  void clear();

private:
  size_t _size{0};
  size_t _capacity{0};
  char *_base{nullptr};
  char *_top{nullptr};
  char *_end{nullptr};
};

class Heap {
public:
  static Heap *get_instance();
  static size_t MAX_CAP;

  ~Heap();

public:
  void *allocate(size_t size);

  void *allocate_meta(size_t size);

  void gc();

private:
  explicit Heap(size_t size);

  void minor_gc();
  void major_gc();

private:
  Space *_eden{};
  Space *_survivor0{};
  Space *_survivor1{};
  Space *_heap{};
  Space *_metaspace{};
};
} // namespace pvm
#endif // PVM_HEAP_HH
