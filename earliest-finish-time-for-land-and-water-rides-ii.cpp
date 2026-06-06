/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
  int findEarliest(vector<int>& s, vector<int>& d, vector<int>& ss, vector<int>& dd){
    int best = INT_MAX;

    for(int i = 0; i < s.size(); ++i)
      best = min(best, s[i] + d[i]);

    int ans = INT_MAX;
    for(int i = 0; i< ss.size(); ++i)
      ans = min(ans, max(best, ss[i]) + dd[i]);

    return ans;
  }

public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
      int landFirst = findEarliest(landStartTime, landDuration, waterStartTime, waterDuration),
          waterFirst = findEarliest(waterStartTime, waterDuration, landStartTime, landDuration);

      return min(landFirst, waterFirst);
    }
};
