#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  char nextGreatestLetter(vector<char> &letters, char target) {
    int l = 0, r = letters.size() - 1, ans = letters[0];
    while (l <= r) {
      int m = l + (r - l >> 1);
      if (letters[m] > target) {
        ans = letters[m];
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    return ans;
  }
};
