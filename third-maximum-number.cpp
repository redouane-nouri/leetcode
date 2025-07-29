#include <climits>
#include <vector>

class Solution {
public:
  int thirdMax(std::vector<int> &nums) {
    long frst = LONG_MIN, scnd = LONG_MIN, thrd = LONG_MIN, sz = nums.size();

    for (int i = 0; i < sz; ++i) {
      if (nums[i] > frst) {
        thrd = scnd;
        scnd = frst;
        frst = nums[i];
      } else if (nums[i] > scnd && nums[i] != frst) {
        thrd = scnd;
        scnd = nums[i];
      } else if (nums[i] > thrd && nums[i] != frst && nums[i] != scnd) {
        thrd = nums[i];
      }
    }

    return thrd == LONG_MIN ? static_cast<int>(frst) : static_cast<int>(thrd);
  }
};
