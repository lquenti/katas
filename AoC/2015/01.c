#include <stdio.h>
int main() {
  int i=0;
  for (char c; (c = getchar()) != EOF;) {
    if (c == '(') {
      i++;
    } else if (c == ')') {
      i--;
    } else {/* who cares */}
  }
  printf("%d\n", i);
}
