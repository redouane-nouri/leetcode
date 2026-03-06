/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  bool checkOnesSegment(string s) {
    const int N = s.size();
    int i = 1;

    while (i < N && s[i] == '1')
      ++i;

    while (i < N && s[i] == '0')
      ++i;

    return i == N;
  }
};
