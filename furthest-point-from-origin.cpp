/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int furthestDistanceFromOrigin(string moves) {
    const uint8_t sz = moves.size();
    uint8_t a[4] = {0};

    for (const char &c : moves)
      ++a[c & 0b11];

    return sz - (min(a[0], a[2]) << 1);
  }
};
