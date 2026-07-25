/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int maxActiveSectionsAfterTrade(string s) {
    const int SZ = s.size();
    int i = 0, prevZ = 0, onesCnt = 0, best = 0;

    while (i < SZ) {
      int start = i++;
      while (s[i] == s[start])
        ++i;

      int len = i - start;

      if (s[start] == '0') {
        if (prevZ)
          best = max(best, prevZ + len);

        prevZ = len;
      } else {
        onesCnt += len;
      }
    }

    return onesCnt + best;
  }
};
