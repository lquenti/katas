#include<ctype.h>
#include<string.h>
char* capitalizeTitle(char* title) {
  size_t n=strlen(title);
  size_t begin_of_word=0;
  while (begin_of_word<n) {
    size_t end_of_word=begin_of_word+1;
    while (title[end_of_word] != '\0' && title[end_of_word] != ' ') ++end_of_word;
    if (end_of_word-begin_of_word>2) {
      title[begin_of_word]=toupper(title[begin_of_word]);
      begin_of_word++;
    }
    while (begin_of_word != end_of_word) {
      title[begin_of_word]=tolower(title[begin_of_word]);
      begin_of_word++;
    }
    begin_of_word++; // jump over whitespace
  }
  return title;
}
