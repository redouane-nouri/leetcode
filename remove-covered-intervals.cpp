/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int removeCoveredIntervals(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end(),
         [](const auto &a, const auto &b) -> bool {
           if (a[0] != b[0])
             return a[0] < b[0];

           return a[1] > b[1];
         });

    int ans = 0, mx = 0;
    for (auto &i : intervals)
      if (i[1] > mx)
        ++ans, mx = i[1];

    return ans;
  }
};
