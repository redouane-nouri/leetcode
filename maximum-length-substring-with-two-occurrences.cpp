/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int maximumLengthSubstring(string s) {
    int freq[26] = {0}, start = 0, ans = 0;
    const int SZ = s.size();

    for (int end = 0; end < SZ; ++end) {
      ++freq[s[end] - 'a'];

      while (freq[s[end] - 'a'] > 2)
        --freq[s[start] - 'a'], ++start;

      ans = max(ans, end - start + 1);
    }

    return ans;
  }
};
