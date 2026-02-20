#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  string makeLargestSpecial(string s) {
    int balance = 0, start = 0;
    const int N = s.size();
    vector<string> specials;

    for (int i = 0; i < N; ++i) {
      balance += s[i] == '1' ? 1 : -1;

      if (balance == 0) {
        specials.push_back(
            "1" + makeLargestSpecial(s.substr(start + 1, i - start - 1)) + "0");
        start = i + 1;
      }
    }

    sort(specials.rbegin(), specials.rend());

    string ans;
    for (const string &s : specials)
      ans += s;

    return ans;
  }
};
