/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
  static constexpr int MOD = 1'000'000'007;

public:
  int zigZagArrays(int n, int l, int r) {
    int range = r - l + 1;
    vector<int> goUp(range, 1), goDown(range, 1);
    vector<int> prefGoUp(range + 1, 0), prefGoDown(range + 1, 0);

    for (int step = 2; step <= n; ++step) {
      for (int v = 0; v < range; ++v)
        prefGoUp[v + 1] = (prefGoUp[v] + goUp[v]) % MOD,
                     prefGoDown[v + 1] = (prefGoDown[v] + goDown[v]) % MOD;

      for (int v = 0; v < range; ++v)
        goUp[v] = (prefGoDown[range] - prefGoDown[v + 1] + MOD) % MOD,
        goDown[v] = prefGoUp[v];
    }

    int ans = 0;
    for (int v = 0; v < range; ++v)
      ans = (((ans + goDown[v]) % MOD) + goUp[v]) % MOD;

    return ans;
  }
};
