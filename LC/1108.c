#include <stdlib.h>
char * defangIPaddr(char * address){
  char *ret = calloc(3*4+3*4+1, sizeof(char));
  size_t i = 0;
  while (*address) {
    if (*address == '.') {
      ret[i] = '['; i++;
      ret[i] = '.'; i++;
      ret[i] = ']'; i++;
    } else {
      ret[i] = *address; i++;
    }
    address++;
  }
  return ret;
}
