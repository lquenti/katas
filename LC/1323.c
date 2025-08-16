int maximum69Number(int num) {
  int digits[10] = {0};
  int i;
  for (i=0; num; num /= 10) {
    digits[i++] = num%10;
  }
  for (int j=i-1; j>=0; --j) {
    if (digits[j] == 6) {
      digits[j] = 9;
      break;
    }
  }
  for (int j=i-1; j>=0; --j) {
    num *= 10;
    num += digits[j];
  }
  return num;
}
