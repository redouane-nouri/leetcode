/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int minimumPushes(string word) {
    int sz = word.size(), ans = 0;

    for (int i = 1; sz > 0; ++i, sz -= 8)
      ans += i * min(8, sz);

    return ans;
  }
};
