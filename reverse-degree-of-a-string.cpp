/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int reverseDegree(string s) {
    const int N = s.size();

    int ans = 0;
    for (int i = 0; i < N; ++i)
      ans += ('z' - s[i] + 1) * (i + 1);

    return ans;
  }
};
