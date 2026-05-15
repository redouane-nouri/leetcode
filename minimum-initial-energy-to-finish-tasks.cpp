/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](auto& a, auto& b) {
            return a[1] - a[0] < b[1] - b[0];
        });

        int ans = 0;
        for (auto& t : tasks)
            ans = max(ans + t[0], t[1]);

        return ans;
    }
};
