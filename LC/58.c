#include<string.h>
int lengthOfLastWord(char* s) {
  int N=strlen(s);
  while (s[N] == ' ' || s[N] == '\0') N--;
  int n=N-1;
  while (n>=0 && s[n]!=' ') n--;
  return N-n;
}
