#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  string reverseWords(string s) {
    const int N = s.size();
    string ans;
    for (int i = N - 1; i >= 0; --i) {
      if (s[i] == ' ')
        continue;
      int l = 0;
      while (i >= 0 && s[i] != ' ') {
        ++l;
        --i;
      }
      ans.append(s.substr(i + 1, l));
      ans.push_back(' ');
    }
    ans.pop_back();
    return ans;
  }
};
