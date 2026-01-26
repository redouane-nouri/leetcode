#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<vector<int>> minimumAbsDifference(vector<int> &arr) {
    const int N = arr.size();
    sort(arr.begin(), arr.end());
    int mn = 1e7;
    for (int i = 1; i < N; ++i)
      mn = min(mn, arr[i] - arr[i - 1]);
    vector<vector<int>> ans;
    for (int i = 1; i < N; ++i)
      if (arr[i] - arr[i - 1] == mn)
        ans.push_back({arr[i - 1], arr[i]});
    return ans;
  }
};
