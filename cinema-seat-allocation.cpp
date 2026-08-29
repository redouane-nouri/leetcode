/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxNumberOfFamilies(int n, vector<vector<int>> &reservedSeats) {
    bitset<8> l("00001111"), m("11000011"), r("11110000");

    unordered_map<int, bitset<8>> mp;
    for (const auto &r : reservedSeats)
      if (r[1] >= 2 && r[1] <= 9)
        mp[r[0]].set(r[1] - 2);

    int ans = (n - mp.size()) << 1;
    for (auto &[i, mask] : mp)
      if ((mask | l) == l || (mask | m) == m || (mask | r) == r)
        ++ans;

    return ans;
  }
};
