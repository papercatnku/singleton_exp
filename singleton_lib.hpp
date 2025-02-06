#pragma once

#include <memory>
#include <mutex>
#include <vector>

class Foo {
 public:
  static Foo& getInstance();
  static void ranInitData(size_t sz);

  void print();

 private:
  Foo() = default;
  ~Foo() = default;
  Foo(const Foo&) = delete;
  Foo& operator=(const Foo&) = delete;

  std::vector<unsigned char> data;
  std::mutex mtx;  // 添加 mutex 成员变量
};