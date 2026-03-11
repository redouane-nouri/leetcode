/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int bitwiseComplement(int n) {
    if (!n)
      return 1;

    return ~n & ((1 << bit_width((unsigned int)n)) - 1);
  }
};
