#include <stdbool.h>
#include <string.h>
int canBeTypedWords(char* text, char* brokenLetters) {
  size_t textlen = strlen(text), broken_letters_n = strlen(brokenLetters);
  bool not_broken = true;
  int cnt = 0;
  for (size_t i=0; i<textlen; ++i) {
    if (text[i] == ' ') {
      if (not_broken) {
        cnt++;
      }
      not_broken = true;
    }
    for (size_t j=0; j<broken_letters_n; ++j) {
      if (text[i] == brokenLetters[j]) {
        not_broken = false;
        break;
      }
    }
  }
  if (not_broken) {
    cnt++;
  }
  return cnt;
}
