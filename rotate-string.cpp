/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  bool rotateString(string s, string goal) {
    if (s.length() != goal.length())
      return false;

    string ss = s + s;

    return ss.find(goal) != string::npos;
  }
};
