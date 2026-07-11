/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int numberOfSubstrings(string s) {
    vector<int> pos = {-1, -1, -1};
    const int N = s.size();
    int ans = 0;

    for (int i = 0; i < N; ++i)
      pos[s[i] - 'a'] = i, ans += 1 + min({pos[0], pos[1], pos[2]});

    return ans;
  }
};
