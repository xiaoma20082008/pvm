//
// Created by chunxiao ma on 2021/12/8.
//

#ifndef PVM_COMMON_HH
#define PVM_COMMON_HH

#define nil nullptr

#define __no_copy__(clazz)                                                                                             \
private:                                                                                                               \
  clazz(const clazz &) = delete;                                                                                       \
  clazz &operator=(const clazz &) = delete;

#define __no_move__(clazz)                                                                                             \
private:                                                                                                               \
  clazz(clazz &&) = delete;                                                                                            \
  clazz &operator=(clazz &&) = delete;

#endif // PVM_COMMON_HH
