/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int maxDistance(vector<int> &colors) {
    const int N = colors.size();
    int ans = 0;
    bitset<101> bs;

    for (int i = 0; i < N - 1; ++i) {
      if (bs[colors[i]])
        continue;

      int j = N - 1;

      while (colors[i] == colors[j])
        --j;

      ans = max(ans, j - i);
      bs.set(colors[i]);
    }

    return ans;
  }
};
