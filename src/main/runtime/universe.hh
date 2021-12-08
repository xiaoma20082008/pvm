//
// Created by chunxiao ma on 2021/11/3.
//

#ifndef PVM_UNIVERSE_HH
#define PVM_UNIVERSE_HH
namespace pvm {
class Heap;
class CodeObject;
class PyObject;

class Universe {
public:
  static void Genesis();

  static void Destroy();

public:
  static PyObject *pyTrue;
  static PyObject *pyFalse;
  static PyObject *pyNone;
  static Heap *heap;
  static CodeObject *code;
};
} // namespace pvm
#endif // PVM_UNIVERSE_HH
