//
// Created by chunxiao ma on 2021/11/22.
//

#ifndef PVM_FRAME_OBJECT_HH
#define PVM_FRAME_OBJECT_HH
namespace pvm {
class PyDict;
class Block {};
class FrameObject {
public:
  PyDict *locals();

private:
  FrameObject *_caller;
  int _pc{0};
};
} // namespace pvm
#endif // PVM_FRAME_OBJECT_HH
