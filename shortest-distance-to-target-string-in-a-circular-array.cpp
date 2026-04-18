/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int eucMod(int a, int b) { return (a % b + abs(b)) % abs(b); };

class Solution {
public:
  int closestTarget(vector<string> &words, string target, int startIndex) {
    const int N = words.size();
    int l = eucMod(startIndex - 1, N), r = startIndex, rc = 0, lc = 0;

    while (lc + rc < N) {
      if (words[r] == target)
        return rc;

      r = eucMod(r + 1, N);
      ++rc;

      if (lc + rc < N) {
        if (words[l] == target)
          return lc + 1;

        l = eucMod(l - 1, N);
        ++lc;
      }
    }

    return -1;
  }
};
