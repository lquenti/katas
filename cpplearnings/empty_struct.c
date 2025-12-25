#include <stdio.h>

// this code returns
// 1 in C++ (each object has a unique adress)
// 0 with gcc
// 0 + warning with gcc -Wpedantic (C grammar doesnt even allow empty structs)

struct A{};

int main() {
  struct A a;
  printf("%zu\n", sizeof(a));
}
