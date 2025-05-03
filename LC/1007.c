#include <limits.h>
#include<stdbool.h>
#define MIN(a,b) (((a)<(b))?(a):(b))
int minDominoRotations(int* tops, int topsSize, int* bottoms, int bottomsSize) {
  int ret = -1;
  for (int x=0; x<=6; ++x) {
    bool possible=true;
    for (int i=0; i<topsSize; ++i) {
      if (tops[i] != x && bottoms[i] != x) {
        possible = false;
        break;
      }
    }
    if (possible) {
      int min_top = 0;
      int min_btm = 0;
      for (int i=0; i<topsSize; ++i) {
        if (tops[i] != x) min_top++;
        if (bottoms[i] != x) min_btm++;
      }
      int min = MIN(min_top, min_btm);
      if (ret == -1 || min < ret) {
        ret = min;
      }
    }
  }
  return ret;
}
int main() {
  printf("Hello, World!\n");
}
