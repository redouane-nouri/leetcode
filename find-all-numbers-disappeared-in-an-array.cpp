#include <cstdlib>
#include <utility>
#include <vector>

class Solution {
public:
  std::vector<int> findDisappearedNumbers(std::vector<int> &nums) {
    std::vector<int> res;
    int sz = nums.size();

    for (int i = 0; i < sz; ++i) {
      int indx = std::abs(nums[i]) - 1;
      nums[indx] = -std::abs(nums[indx]);
    }

    for (int i = 0; i < sz; ++i)
      if (nums[i] > 0)
        res.push_back(i + 1);

    return res;
  }
};
