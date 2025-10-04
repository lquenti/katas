#include<string.h>
int possibleStringCount(char* word) {
  int res=1, i=0;
  size_t n=strlen(word);
  while (i<n) {
    // check how often current occurs
    int cnt=1;
    while (i+cnt<n && word[i+cnt] == word[i]) {
      cnt++;
    }
    res+=cnt-1;
    i+=cnt;
  }
  return res;
}
