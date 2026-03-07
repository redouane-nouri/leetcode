#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int numSteps(string s) {
    int steps = 0;
    bool carry = false;

    for (const char &c : s | views::drop(1) | views::reverse) {
      if (c == '0') {
        steps += carry ? 2 : 1;
      } else {
        steps += carry ? 1 : 2;
        carry = true;
      }
    }

    return steps + carry;
  }
};
