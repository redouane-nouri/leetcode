#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <vector>

class Solution {
public:
  int minSubarray(std::vector<int> &nums, int p) {
    const int N = nums.size();
    int rem = std::accumulate(nums.begin(), nums.end(), 0LL) % p;

    if (rem == 0)
      return 0;

    std::unordered_map<int, int> modIdxMap;
    modIdxMap[0] = -1;
    int ans = N, sum = 0;

    for (int i = 0; i < N; ++i) {
      sum = (sum + nums[i]) % p;
      int modNeeded = (sum - rem + p) % p;
      auto it = modIdxMap.find(modNeeded);

      if (it != modIdxMap.end())
        ans = std::min(ans, i - modIdxMap[modNeeded]);

      modIdxMap[sum] = i;
    }

    return ans == N ? -1 : ans;
  }
};
