#include<limits.h>
#include<string.h>
int maxDifference(char* s) {
  int n = strlen(s);
  int freqs[26] = {0};
  for (int i=0; i<n; ++i) {
    freqs[s[i]-'a']++;
  }
  int max_odd=-1, min_even=INT_MAX;
  for (int i=0; i<26; ++i) {
    if (freqs[i]%2==1 && freqs[i] > max_odd) {
      max_odd = freqs[i];
    }
    if (freqs[i]%2==0 && freqs[i] != 0 && freqs[i] < min_even) {
      min_even = freqs[i];
    }
  }
  return max_odd - min_even;
}
