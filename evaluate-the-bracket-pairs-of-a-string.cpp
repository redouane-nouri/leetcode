/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
  string evaluate(string s, vector<vector<string>> &knowledge) {
    unordered_map<string, string> mp;
    for (auto &k : knowledge)
      mp[k[0]] = k[1];

    string res, key;
    bool isKey = false;
    for (char &c : s) {
      switch (c) {
      case '(':
        isKey = true;
        break;

      case ')':
        isKey = false;
        mp.count(key) ? res += mp[key] : res += '?';
        key.clear();
        break;

      default:
        isKey ? key += c : res += c;
        break;
      }
    }

    return res;
  }
};
