
class Solution {
public:
  int searchInsert(vector<int> &nums, int target) {

    int mid_index, left_index = 0, right_index = nums.size() - 1;

    while (left_index <= right_index) {
      mid_index = left_index + (right_index - left_index) / 2;

      if (nums[mid_index] == target) {
        return mid_index;
      } else if (nums[mid_index] > target) {
        right_index = mid_index - 1;
      } else {
        left_index = mid_index + 1;
      }
    }
    return left_index;
  }
};
