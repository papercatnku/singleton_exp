#include <cstdio>

#include "wrapper.hpp"

using namespace std;
int main(int argc, char* argv[]) {
  for (int i = 0; i < 10; i++) {
    printf("#%d\t", i);
    resetData(i);
    printData();
  }
  return 0;
}