int largestAltitude(int* gain, int gainSize) {
  int start=0, max=0;
  for (int i=0; i<gainSize; ++i) {
    start+=gain[i];
    if (start>max) {
      max=start;
    }
  }
  return max;
}
