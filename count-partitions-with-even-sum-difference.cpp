#include <numeric>
#include <vector>

class Solution {
public:
  int countPartitions(std::vector<int> &nums) {
    return std::accumulate(nums.begin(), nums.end(), 0) % 2 == 0
               ? nums.size() - 1
               : 0;
  }
};
