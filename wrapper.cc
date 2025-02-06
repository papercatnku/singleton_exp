#include "wrapper.hpp"

#include <cstdio>
#include <iostream>

#include "singleton_lib.hpp"

void resetData(size_t sz) {
  Foo::ranInitData(sz);
  return;
}

void printData() {
  Foo& foo = Foo::getInstance();
  foo.print();
  return;
}
