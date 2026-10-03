/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> maxDepthAfterSplit(string seq) {
    int d = 0;
    vector<int> ans;
    ans.reserve(seq.size());

    for (const char &c : seq) {
      switch (c) {
      case '(':
        ans.push_back(++d % 2);
        break;

      default:
        ans.push_back(d-- % 2);
      }
    }

    return ans;
  }
};
