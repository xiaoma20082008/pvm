//
// Created by chunxiao ma on 2021/11/3.
//

#include "utils/bufferedInputStream.hh"

namespace pvm {

BufferedInputStream::BufferedInputStream(const char *filename) {
  _filename = filename;
  _file = std::fopen(_filename, "rb");
  _index = 0;
  std::fread(_buffer, BUFFER_LEN * sizeof(char), 1, _file);
}

BufferedInputStream::~BufferedInputStream() { Close(); }

char BufferedInputStream::Read() {
  if (_index < BUFFER_LEN) {
    return _buffer[_index++];
  } else {
    _index = 0;
    std::fread(_buffer, BUFFER_LEN * sizeof(char), 1, _file);
    return _buffer[_index++];
  }
}

int BufferedInputStream::ReadInt() {
  int b1 = Read() & 0xff;
  int b2 = Read() & 0xff;
  int b3 = Read() & 0xff;
  int b4 = Read() & 0xff;
  return b4 << 24 | b3 << 16 | b2 << 8 | b1;
}

double BufferedInputStream::ReadFloat() {
  char t[8];
  for (int i = 0; i < 8; i++) {
    t[i] = Read();
  }
  return *(double *)t;
}

char BufferedInputStream::Peek() {
  if (_index < BUFFER_LEN) {
    return _buffer[_index];
  } else {
    _index = 0;
    std::fread(_buffer, BUFFER_LEN * sizeof(char), 1, _file);
    return _buffer[_index];
  }
}

void BufferedInputStream::Undo() { _index--; }

void BufferedInputStream::Close() {
  if (_file != nullptr) {
    std::fclose(_file);
    _file = nullptr;
  }
}

} // namespace pvm