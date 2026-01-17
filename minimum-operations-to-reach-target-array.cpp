#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minOperations(vector<int> &nums, vector<int> &target) {
    const int N = nums.size();
    unordered_set<int> ans;
    for (int i = 0; i < N; ++i) {
      if (nums[i] != target[i])
        ans.insert(nums[i]);
    }
    return ans.size();
  }
};
