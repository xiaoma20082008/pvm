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
  bool HasRemaining(size_t size);
  bool Contains(char *obj);
  void *Alloc(size_t size);
  size_t Size();
  void Clear();

private:
  size_t _size{0};
  size_t _capacity{0};
  char *_base{nullptr};
  char *_top{nullptr};
  char *_end{nullptr};
};

class Heap {
public:
  static Heap *GetInstance();
  static size_t MAX_CAP;

  ~Heap();

public:
  void *Allocate(size_t size);

  void *AllocateMeta(size_t size);

  void GC();

private:
  explicit Heap(size_t size);

  void MinorGC();
  void MajorGC();

private:
  Space *_eden{};
  Space *_survivor0{};
  Space *_survivor1{};
  Space *_heap{};
  Space *_metaspace{};
};
} // namespace pvm
#endif // PVM_HEAP_HH
