#include<stdlib.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

struct {
  int *data;
  size_t cnt;
  size_t cap;
} vec_int;

#define vec_push(xs, x) \
  do { \
    if (xs.cnt >= xs.cap) { \
      xs.cap = (xs.cap == 0) ? 16 : xs.cap*2; \
      xs.data = realloc(xs.data, xs.cap * sizeof(*xs.data)); \
    } \
    xs.data[xs.cnt++] = x; \
  while (0)
