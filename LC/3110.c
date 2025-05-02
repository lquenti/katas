#include <stdlib.h>
#include <string.h>
int scoreOfString(char* s) {
  int score=0, n = strlen(s);
  for (int i=0; i<n-1; ++i) {
    score += abs((int)(s[i])-(int)(s[i+1]));
  }
  return score;
}
