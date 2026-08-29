/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  string shortestBeautifulSubstring(string s, int k) {
    const int SZ = s.size();
    int cnt = 0;
    string ans;

    for (int l = 0, r = 0; r < SZ; ++r) {
      cnt += s[r] == '1';

      while (cnt > k || s[l] == '0')
        cnt -= s[l] == '1', ++l;

      if (cnt == k) {
        string sub = s.substr(l, r - l + 1);
        if (ans.empty() || sub.length() < ans.length() ||
            sub.length() == ans.length() && sub < ans)
          ans = move(sub);
      }
    }

    return ans;
  }
};
