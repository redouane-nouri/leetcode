#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int minimumPairRemoval(vector<int> &nums) {
    const int N = nums.size();
    vector<int> next(N);
    iota(next.begin(), next.end(), 1);
    next[N - 1] = -1;
    int count = 0;
    while (N - count > 1) {
      int minIdx = 0, minSum = nums[minIdx] + nums[next[minIdx]];
      bool sorted = true;
      for (int i = 0; i != -1 && next[i] != -1; i = next[i]) {
        if (nums[i] > nums[next[i]])
          sorted = false;
        int s = nums[i] + nums[next[i]];
        if (s < minSum) {
          minIdx = i;
          minSum = s;
        }
      }
      if (sorted)
        return count;
      ++count;
      nums[minIdx] = minSum;
      next[minIdx] = next[next[minIdx]];
    }
    return count;
  }
};
