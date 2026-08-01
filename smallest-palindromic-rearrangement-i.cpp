/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  string smallestPalindrome(string s) {
    const int SZ = s.size();
    int count[26] = {0}, l = 0, r = SZ - 1;

    for (int i = 0; i < SZ >> 1; ++i)
      ++count[s[i] - 'a'];

    for (int i = 0; i < 26; ++i) {
      while (count[i]) {
        char c = i + 'a';
        s[l++] = c, s[r--] = c, --count[i];
      }
    }

    return s;
  }
};
