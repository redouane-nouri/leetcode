#include <unordered_set>
#include <vector>

class Solution {
public:
  int longestConsecutive(std::vector<int> &nums) {
    std::unordered_set<int> numsSet(nums.begin(), nums.end());
    int res = 0;

    for (int num : numsSet) {
      if (!numsSet.count(num++ - 1)) {
        int seq = 1;
        while (numsSet.count(num++))
          ++seq;

        if (seq > res)
          res = seq;
      }
    }

    return res;
  }
};
