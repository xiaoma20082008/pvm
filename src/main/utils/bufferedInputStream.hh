//
// Created by chunxiao ma on 2021/11/3.
//

#ifndef PVM_BUFFERED_INPUT_STREAM_HH
#define PVM_BUFFERED_INPUT_STREAM_HH
#include <cstdio>

namespace pvm {

static constexpr int BUFFER_LEN = 4096;

class BufferedInputStream {
public:
  explicit BufferedInputStream(const char *filename);

  ~BufferedInputStream();

  char read();

  char peek();

  int read_int();

  void undo();

  void close();

private:
  std::FILE *_file{nullptr};
  const char *_filename{nullptr};
  char _buffer[BUFFER_LEN]{0};
  unsigned short _index{0};
};

} // namespace pvm
#endif // PVM_BUFFERED_INPUT_STREAM_HH
