/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int maxDepth(string s) {
    int cnt = 0, ans = 0;

    for (const char &c : s) {
      switch (c) {
      case '(':
        ++cnt;
        break;

      case ')':
        --cnt;
      }

      ans = max(ans, cnt);
    }

    return ans;
  }
};
