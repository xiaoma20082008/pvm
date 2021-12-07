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

BufferedInputStream::~BufferedInputStream() { close(); }

char BufferedInputStream::read() {
  if (_index < BUFFER_LEN) {
    return _buffer[_index++];
  } else {
    _index = 0;
    std::fread(_buffer, BUFFER_LEN * sizeof(char), 1, _file);
    return _buffer[_index++];
  }
}

int BufferedInputStream::read_int() {
  int b1 = read() & 0xff;
  int b2 = read() & 0xff;
  int b3 = read() & 0xff;
  int b4 = read() & 0xff;
  return b4 << 24 | b3 << 16 | b2 << 8 | b1;
}

char BufferedInputStream::peek() {
  if (_index < BUFFER_LEN) {
    return _buffer[_index];
  } else {
    _index = 0;
    std::fread(_buffer, BUFFER_LEN * sizeof(char), 1, _file);
    return _buffer[_index];
  }
}

void BufferedInputStream::undo() { _index--; }

void BufferedInputStream::close() {
  if (_file != nullptr) {
    std::fclose(_file);
    _file = nullptr;
  }
}

} // namespace pvm