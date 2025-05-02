#include <stdlib.h>
double* convertTemperature(double celsius, int* returnSize) {
  double *ret = malloc(2*sizeof(double));
  *returnSize = 2;
  ret[0] = celsius + 273.15;
  ret[1] = celsius * 1.80 + 32.00;
  return ret;
}
