#include "singleton_lib.hpp"

#include <chrono>
#include <cstdio>
#include <iostream>
#include <random>
#include <mutex>

using namespace std;

Foo& Foo::getInstance() {
  static Foo instance;
  return instance;
}

void Foo::ranInitData(size_t sz) {
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<int> dis(0, 255);

  Foo& foo = getInstance();
  lock_guard<mutex> lock(foo.mtx); // 添加锁
  foo.data.resize(sz);
  for (size_t i = 0; i < sz; ++i) {
    foo.data[i] = (unsigned char)dis(gen);
  }
  return;
}

void Foo::print() {
  Foo& foo = getInstance();
  lock_guard<mutex> lock(foo.mtx); // 添加锁
  // print this
  cout << this << "\t[";
  int num = data.size();
  for (int i = 0; i < num - 1; ++i) {
    cout << static_cast<int>(data[i]) << "\t";
  }
  if (num > 0) {
    cout << static_cast<int>(data[data.size() - 1]) << "]";
  } else {
    cout << "]";
  }
  cout << endl;
  return;
}
