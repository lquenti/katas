int numWaterBottles(int numBottles, int numExchange) {
  int res=0;
  int full=numBottles, empty=0;
  while (full) {
    res+=full; empty+=full; full=0;
    full = empty/numExchange; empty %= numExchange;
  }
  return res;
}
