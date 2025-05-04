int numEquivDominoPairs(int** dominoes, int dominoesSize, int* dominoesColSize) {
  int ret=0;
  int cnts[100] = {0};
  for (int i=0; i<dominoesSize; ++i) {
    int small, large;
    if (dominoes[i][0] < dominoes[i][1]) {
      small = dominoes[i][0];
      large = dominoes[i][1];
    } else {
      large = dominoes[i][0];
      small = dominoes[i][1];
    }
    cnts[(small-1)+10*(large-1)]++;
  }
  for (int i=0; i<100; ++i) {
    int n = cnts[i];
    ret += (n*(n-1))/2;
  }
  return ret;
}
