#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* pushDominoes(char* curr) {
  const int n = strlen(curr);
  char *last = calloc(n+1, sizeof(char));

  // base case
  if (n<=1) return curr;

  while (strcmp(last, curr) != 0) {
    strcpy(last, curr);
    // const cases: first and last
    if (last[0] == '.' && last[1] == 'L') {
      curr[0] = 'L';
    }
    if (last[n-1] == '.' && last[n-2] == 'R') {
      curr[n-1] = 'R';
    }
    for (int i=1; i<n-1; ++i) {
      if (last[i] == '.') {
        if (last[i+1] == 'L' && last[i-1] != 'R') {
          curr[i] = 'L';
        } else if (last[i-1] == 'R' && last[i+1] != 'L') {
          curr[i] = 'R';
        }
      }
    }
  }
  free(last);
  return curr;
}

int main() {
  char dominoes[] = "RR.L";
  pushDominoes(dominoes);
}
