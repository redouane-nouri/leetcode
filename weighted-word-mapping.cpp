/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  string mapWordWeights(vector<string> &words, vector<int> &weights) {
    string s;

    for (const string &w : words) {
      int weight = 0;

      for (const char &c : w)
        weight += weights[c - 'a'];

      s.push_back('z' - (weight % 26));
    }

    return s;
  }
};
