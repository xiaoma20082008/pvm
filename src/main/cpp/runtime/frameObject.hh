//
// Created by chunxiao ma on 2021/11/22.
//

#ifndef PVM_FRAME_OBJECT_HH
#define PVM_FRAME_OBJECT_HH
#include "utils/arrayList.hh"
#include "utils/common.hh"

namespace pvm {
class PyDict;
class PyList;
class PyFunc;
class PyString;
class CodeObject;
class OopClosure;

class Block {
public:
  Block();
  Block(unsigned char type, unsigned int target, int level);
  ~Block();

  Block(const Block &rhs);
  Block &operator=(const Block &);

  __no_move__(Block);

public:
  unsigned char _type{0};
  unsigned int _target{0};
  int _level{0};
};

class FrameObject {
public:
  FrameObject(CodeObject *code);
  FrameObject(PyFunc *func, ObjList args, int op_arg);
  ~FrameObject();

  __no_copy__(FrameObject);
  __no_move__(FrameObject);

public:
  bool HasNext();
  unsigned char GetOpCode();

  PyString *GetFileName() const;
  PyString *GetFuncName() const;
  int GetLineno();

  // region getter/setter

  PyList *GetStack() const;
  ArrayList<Block *> *GetLoopStack() const;
  ArrayList<PyObject *> *GetConsts() const;
  ArrayList<PyObject *> *GetNames() const;
  PyDict *GetGlobals() const;
  PyDict *GetLocals() const;
  PyList *GetClosure() const;
  CodeObject *GetCode() const;
  FrameObject *GetCaller() const;
  int GetPc() const;
  bool IsEntryFrame() const;

  void SetStack(PyList *stack);
  void SetLoopStack(ArrayList<Block *> *loop_stack);
  void SetConsts(ArrayList<PyObject *> *consts);
  void SetNames(ArrayList<PyObject *> *names);
  void SetGlobals(PyDict *globals);
  void SetLocals(PyDict *locals);
  void SetClosure(PyList *closure);
  void SetCode(CodeObject *code);
  void SetCaller(FrameObject *caller);
  void SetPc(int pc);
  void SetEntryFrame(bool entry_frame);

  // endregion getter/setter

  void Accept(OopClosure *f);

private:
  PyList *_stack{nil};
  ArrayList<Block *> *_loop_stack{nil};

  ArrayList<PyObject *> *_consts{nil};
  ArrayList<PyObject *> *_names{nil};

  PyDict *_globals{nil};
  PyDict *_locals{nil};
  PyList *_closure{nil};

  CodeObject *_code{nil};
  FrameObject *_caller{nil};
  int _pc{0};
  bool _entry_frame{false};
};
} // namespace pvm
#endif // PVM_FRAME_OBJECT_HH
