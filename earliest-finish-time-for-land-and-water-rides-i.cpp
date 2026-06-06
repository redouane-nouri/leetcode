/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration,
                           vector<int>& waterStartTime, vector<int>& waterDuration) {
        int ans = INT_MAX;

        for (int i = 0; i < landStartTime.size(); ++i) {
            for (int j = 0; j < waterStartTime.size(); ++j) {
                int finishLand = landStartTime[i] + landDuration[i],
                    startWater = max(finishLand, waterStartTime[j]),
                    finishWater = startWater + waterDuration[j];

                ans = min(ans, finishWater);

                int finishWater2 = waterStartTime[j] + waterDuration[j],
                    startLand = max(finishWater2, landStartTime[i]), 
                    finishLand2 = startLand + landDuration[i];
                
                ans = min(ans, finishLand2);
            }
        }

        return ans;
    }
};
