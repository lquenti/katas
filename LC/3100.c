int maxBottlesDrunk(int numBottles, int numExchange) {
  int full=numBottles, empty=0, drunk=0;
  while (1) {
    // If possible, drink what you have
    drunk += full; empty+=full; full=0;
    // Check if you can transfer them to new full bottles
    while (empty >= numExchange) {
      full++; empty-=numExchange; numExchange++;
    }
    // If, at the end, we have nothing to do, break out
    if (!full) {
      break;
    }
  }
  return drunk;
}
