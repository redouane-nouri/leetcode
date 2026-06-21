/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int maxIceCream(vector<int> &costs, int coins) {
    vector<int> count(100001, 0);

    for (int &c : costs)
      ++count[c];

    int ans = 0;
    for (int p = 1; p <= 100000 && coins >= p; ++p)
      while (count[p] > 0 && coins >= p)
        coins -= p, ++ans, --count[p];

    return ans;
  }
};
