/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int minBishopMoves(vector<int> &source, vector<int> &target) {
    auto inWhite = [](const int &r, const int &c) -> bool {
      if (r % 2)
        return c % 2;

      return !(c % 2);
    };

    bool tw = inWhite(target[0], target[1]), sw = inWhite(source[0], source[1]);

    if (sw && !tw || !sw && tw)
      return -1;

    if (abs(target[0] - source[0]) == abs(target[1] - source[1]))
      return 1;

    return 2;
  }
};
