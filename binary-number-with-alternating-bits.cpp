#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  bool hasAlternatingBits(int n) {
    int prevBit = n & 1;
    n >>= 1;

    while (n) {
      if ((n & 1) == prevBit)
        return false;

      prevBit = n & 1;
      n >>= 1;
    }

    return true;
  }
};
