/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool sumGame(string num) {
    const int SZ = num.size();

    int num1 = 0, qst1 = 0;
    for (int i = 0; i < SZ >> 1; ++i)
      if (num[i] == '?')
        ++qst1;
      else
        num1 += num[i] - '0';

    int num2 = 0, qst2 = 0;
    for (int i = SZ >> 1; i < SZ; ++i)
      if (num[i] == '?')
        ++qst2;
      else
        num2 += num[i] - '0';

    return ((qst1 + qst2) % 2 == 1) || (2 * (num1 - num2) != 9 * (qst2 - qst1));
  }
};
