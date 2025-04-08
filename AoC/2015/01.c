#include <limits.h>
#include <stdio.h>
int main() {
  int i=0; int minus_one_idx=1;
  for (char c; (c = getchar()) != EOF; minus_one_idx++) {
    if (c == '(') {
      i++;
    } else if (c == ')') {
      i--;
    } else {/* who cares */}
    if (i == -1 && minus_one_idx > 0) {
      printf("%d\n", minus_one_idx);
      // i only want to know it first time, dont care anymore
      minus_one_idx = INT_MIN;
    }
  }
  printf("%d\n", i);
}
