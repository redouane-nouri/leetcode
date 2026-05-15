/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums, const int limit) {
	    vector<int> d((limit << 1) + 2, 0);
	    const int N = nums.size();

	    for(int i = 0; i < (N >> 1); ++i){
		    int a = min(nums[i], nums[N - 1 - i]);
		    int b = max(nums[i], nums[N - 1 - i]);
		    
		    d[2] += 2, d[(limit << 1) + 1] -= 2;
		    d[a + 1] -= 1, d[b + limit + 1] += 1;
		    d[a + b] -= 1, d[a + b + 1] += 1;
	    }

	    int ans = INT_MAX, c = 0;
	    for(int i = 2; i <= (limit << 1); ++i)
		    c += d[i], ans = min(ans, c);

	    return ans;
    }
};
