/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  bool judgeCircle(string moves) {
    int x = 0, y = 0;

    for (char &c : moves)
      switch (c) {
      case 'U':
        ++y;
        break;

      case 'R':
        ++x;
        break;

      case 'D':
        --y;
        break;

      case 'L':
        --x;
      }

    return x == 0 && y == 0;
  }
};
