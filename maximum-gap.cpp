#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int maximumGap(vector<int> &nums) {
    const int N = nums.size();

    if (N < 2)
      return 0;

    int mn = *min_element(nums.begin(), nums.end());
    int mx = *max_element(nums.begin(), nums.end());

    int bucketSize = max(1, (mx - mn) / (N - 1));
    int bucketCount = (mx - mn) / bucketSize + 1;

    vector<int> bucketMin(bucketCount, INT_MAX);
    vector<int> bucketMax(bucketCount, INT_MIN);

    for (const int &num : nums) {
      int idx = (num - mn) / bucketSize;
      bucketMin[idx] = min(bucketMin[idx], num);
      bucketMax[idx] = max(bucketMax[idx], num);
    }

    int prevMax = mn;
    int ans = 0;

    for (int i = 0; i < bucketCount; ++i) {
      if (bucketMin[i] != INT_MAX) {
        ans = max(ans, bucketMin[i] - prevMax);
        prevMax = bucketMax[i];
      }
    }

    return ans;
  }
};
