/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int minimumPushes(string word) {
    vector<int> cnt(26, 0);

    for (char &c : word)
      ++cnt[c - 'a'];

    sort(cnt.rbegin(), cnt.rend());

    int ans = 0;
    for (int i = 0; i < 26; ++i)
      if (cnt[i])
        ans += cnt[i] * ((i >> 3) + 1);

    return ans;
  }
};
