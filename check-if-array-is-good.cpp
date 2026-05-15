class Solution {
public:
    bool isGood(vector<int>& nums) {
	    const int N = nums.size();
	    vector<int> freq(N, 0);

	    for(const int &x: nums){
		    if(x >= N)
			    return false;

		    if(x == N-1 && freq[x] > 1)
			    return false;

		    if(x < N -1 && freq[x] > 0)
			    return false;

		    ++freq[x];
	    }

	    return true;
    }
};
