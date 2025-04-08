#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
int min(int a, int b) {
  return a<b ? a : b;
}
int main() {
  char *line = NULL;
  size_t len = 0;
  int l,w,h;
  long sum=0, sum2=0;
  while (getline(&line, &len, stdin) != EOF) {
    assert(sscanf(line, "%dx%dx%d", &l, &w, &h) == 3);
    sum += 2*l*w + 2*w*h + 2*h*l;
    sum += min(l*w, min(w*h, h*l));

    sum2 += min(l+l+w+w, min(w+w+h+h, l+l+h+h));
    sum2 += l*w*h;
  }
  printf("sum: %ld\n", sum);
  printf("sum2: %ld\n", sum2);
  free(line);
}
