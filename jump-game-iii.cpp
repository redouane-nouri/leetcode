/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
  bool search(vector<int>& v, int i, vector<bool>& vs){
    if(i < 0 || i >= v.size())
      return false;

    if(vs[i])
      return false;

    if(v[i] == 0)
      return true;

    vs[i] = true;

    return search(v, i - v[i], vs) || search(v, i + v[i], vs);
  }

public:
  bool canReach(vector<int>& arr, int start) {
    vector<bool> visited(arr.size(), false);

    return search(arr, start, visited);
  }
};
