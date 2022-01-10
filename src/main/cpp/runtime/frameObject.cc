//
// Created by chunxiao ma on 2021/11/22.
//

#include "runtime/frameObject.hh"
#include "code/codeObject.hh"
#include "memory/gc.hh"
#include "object/pyDict.hh"
#include "object/pyList.hh"
#include "object/pyString.hh"
#include <cassert>

namespace pvm {

Block::Block() {}
Block::Block(unsigned char type, unsigned int target, int level) : _type(type), _target(target), _level(level) {}
Block::~Block() = default;
Block::Block(const Block &rhs) : _type(rhs._type), _target(rhs._target), _level(rhs._level) {}
Block &Block::operator=(const Block &rhs) {
  if (this != &rhs) {
    this->_type = rhs._type;
    this->_target = rhs._target;
    this->_level = rhs._level;
  }
  return *this;
}

FrameObject::FrameObject(CodeObject *codes) {
  _consts = codes->_consts;
  _names = codes->_names;

  _locals = new PyDict();
  _globals = _locals;
  _closure = nil;

  _stack = new PyList();
  _loop_stack = std::vector<Block *>{};

  _code = codes;
  _pc = 0;
  _caller = nil;
  _entry_frame = false;
}

FrameObject::FrameObject(PyFunc *func, std::vector<PyObject *> args, int op_arg) { _locals = new PyDict(); }

FrameObject::~FrameObject() = default;

bool FrameObject::HasNext() { return _pc < _code->_opcodes->Length(); }
unsigned char FrameObject::GetOpCode() { return _code->_opcodes->Value()[_pc++]; }
int FrameObject::GetOpArgs() {
  int byte1 = _code->_opcodes->Value()[_pc++] & 0xff;
  int byte2 = _code->_opcodes->Value()[_pc++] & 0xff;
  return byte2 << 8 | byte1;
}
PyString *FrameObject::GetFileName() const { return _code->_filename; }
PyString *FrameObject::GetFuncName() const { return _code->_name; }
int FrameObject::GetLineno() {
  int lineno = _code->_first_line_no;
  lineno += _pc;
  return lineno;
}
void FrameObject::Accept(OopClosure *f) {
  f->Visit(_stack);
  f->Visit(_loop_stack);

  f->Visit(_consts);
  f->Visit(_names);

  f->Visit(_globals);
  f->Visit(_locals);
  f->Visit(_closure);

  f->Visit(_code);

  if (_caller != nil) {
    _caller->Accept(f);
  }
}

// region getter/setter

PyList *FrameObject::GetStack() const { return _stack; }
std::vector<Block *> FrameObject::GetLoopStack() const { return _loop_stack; }
std::vector<PyObject *> FrameObject::GetConsts() const { return _consts; }
std::vector<PyObject *> FrameObject::GetNames() const { return _names; }
PyDict *FrameObject::GetGlobals() const { return _globals; }
PyDict *FrameObject::GetLocals() const { return _locals; }
PyList *FrameObject::GetClosure() const { return _closure; }
CodeObject *FrameObject::GetCode() const { return _code; }
FrameObject *FrameObject::GetCaller() const { return _caller; }
int FrameObject::GetPc() const { return _pc; }
bool FrameObject::IsEntryFrame() const { return _entry_frame; }

void FrameObject::SetStack(PyList *stack) { _stack = stack; }
void FrameObject::SetLoopStack(std::vector<Block *> loop_stack) { _loop_stack = loop_stack; }
void FrameObject::SetConsts(std::vector<PyObject *> consts) { _consts = consts; }
void FrameObject::SetNames(std::vector<PyObject *> names) { _names = names; }
void FrameObject::SetGlobals(PyDict *globals) { _globals = globals; }
void FrameObject::SetLocals(PyDict *locals) { _locals = locals; }
void FrameObject::SetClosure(PyList *closure) { _closure = closure; }
void FrameObject::SetCode(CodeObject *code) { _code = code; }
void FrameObject::SetCaller(FrameObject *caller) { _caller = caller; }
void FrameObject::SetPc(int pc) { _pc = pc; }
void FrameObject::SetEntryFrame(bool entry_frame) { _entry_frame = entry_frame; }

// endregion getter/setter

} // namespace pvm