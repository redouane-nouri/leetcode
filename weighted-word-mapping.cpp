#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  string mapWordWeights(vector<string> &words, vector<int> &weights) {
    string s;

    for (const string w : words) {
      int weight = 0;

      for (const char &c : w)
        weight += weights[c - 'a'];

      weight = weight % 26;

      s.push_back('z' + weight);
    }

    return s;
  }
};
