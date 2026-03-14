/**
 * @author Redouane Nouri
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  string getHappyString(int n, int k) {
    vector<string> strings;
    string curr = "";

    auto build = [&strings, &k, &curr](this auto &self, int i) -> void {
      if (strings.size() == k)
        return;

      if (i-- == 0) {
        strings.push_back(curr);
        return;
      }

      for (char c = 'a'; c <= 'c'; ++c) {
        if (!curr.empty() && curr.back() == c)
          continue;

        curr.push_back(c);
        self(i);
        curr.pop_back();
      }
    };

    build(n);

    if (strings.size() < k)
      return "";

    return strings[k - 1];
  }
};
