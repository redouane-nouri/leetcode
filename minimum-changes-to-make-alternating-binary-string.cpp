/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int minOperations(string s) {
    const int N = s.size();
    int count = 0;

    for (int i = 0; i < N; ++i)
      if (s[i] - '0' != i % 2)
        ++count;

    return min(N - count, count);
  }
};
