#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> constructTransformedArray(vector<int> &nums) {
    const int N = nums.size();
    vector<int> res(N);

    for (int i = 0; i < N; ++i) {
      int r = (i + nums[i]) % N;
      res[i] = nums[r + (-(r < 0) & N)];
    }

    return res;
  }
};
