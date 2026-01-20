#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int maxProduct(vector<int> &nums) {
    const int N = nums.size();
    int maxProd = nums[0], minProd = nums[0], ans = nums[0];
    for (int i = 1; i < N; ++i) {
      int &num = nums[i];
      if (num < 0)
        swap(maxProd, minProd);
      maxProd = max(num, num * maxProd);
      minProd = min(num, num * minProd);
      ans = max(ans, maxProd);
    }
    return ans;
  }
};
