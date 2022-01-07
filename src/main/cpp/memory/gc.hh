//
// Created by chunxiao ma on 2022/1/4.
//

#ifndef PVM_GC_HH
#define PVM_GC_HH
#include <vector>
namespace pvm {
class Klass;
class PyDict;
class PyFloat;
class PyFunc;
class PyInt;
class PyList;
class PyObject;
class PyString;
class Block;
class Space;
class Heap;
class StringTable;
template <typename T> class ArrayList;
template <typename K, typename V> class Map;

class ObjVisitor {
public:
  virtual void Visit(Klass *obj) = 0;
  virtual void Visit(PyDict *obj) = 0;
  virtual void Visit(PyFloat *obj) = 0;
  virtual void Visit(PyFunc *obj) = 0;
  virtual void Visit(PyInt *obj) = 0;
  virtual void Visit(PyList *obj) = 0;
  virtual void Visit(PyString *obj) = 0;
  virtual void Visit(PyObject *obj) = 0;
  virtual void Visit(std::vector<Block *> obj) = 0;
  virtual void Visit(std::vector<PyObject *> obj) = 0;
  virtual void Visit(std::vector<Klass *> obj) = 0;
  virtual void Visit(Map<PyObject *, PyObject *> *obj) = 0;
  virtual void Visit(StringTable *obj) = 0;
};

class OopClosure : public ObjVisitor {
public:
  OopClosure(Space *from, Space *to, Space *metaspace);
  ~OopClosure();

public:
  virtual void Visit(Klass *obj) override;
  virtual void Visit(PyDict *obj) override;
  virtual void Visit(PyFloat *obj) override;
  virtual void Visit(PyFunc *obj) override;
  virtual void Visit(PyInt *obj) override;
  virtual void Visit(PyList *obj) override;
  virtual void Visit(PyString *obj) override;
  virtual void Visit(PyObject *obj) override;
  virtual void Visit(std::vector<Block *> obj) override;
  virtual void Visit(std::vector<PyObject *> obj) override;
  virtual void Visit(std::vector<Klass *> obj) override;
  virtual void Visit(Map<PyObject *, PyObject *> *obj) override;
  virtual void Visit(StringTable *obj) override;

  virtual void CMS();

private:
  Space *_from{};
  Space *_to{};
  Space *_metaspace{};
};

} // namespace pvm
#endif // PVM_GC_HH
