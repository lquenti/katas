#include<bits/stdc++.h>
using namespace std;
bool inline __attribute__((always_inline)) works(int spell, int potion, long long success) {
  return static_cast<long long>(spell) * potion >= success;
}

class Solution {
  public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success) {
      int n = spells.size();
      int m = potions.size();
      vector<int> result(n);

      vector<pair<int, int>> indexed_spells(n);
      for (int i = 0; i < n; ++i) {
        indexed_spells[i] = {spells[i], i};
      }

      sort(indexed_spells.begin(), indexed_spells.end());
      sort(potions.begin(), potions.end());

      int potion_ptr = m - 1;
      for (int i = 0; i < n; ++i) {
        int current_spell = indexed_spells[i].first;
        int original_index = indexed_spells[i].second;

        while (potion_ptr >= 0 && works(current_spell, potions[potion_ptr], success)) {
          potion_ptr--;
        }

        result[original_index] = m - (potion_ptr + 1);
      }
      return result;
    }
};
