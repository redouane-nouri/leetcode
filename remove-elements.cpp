class Solution {
public:
  int removeElement(vector<int> &nums, int val) {
    int counter = 0;

    for (uint8_t i = 0; i < nums.size(); i++) {
      if (nums[i] != val) {
        nums[counter] = nums[i];
        counter++;
      }
    }

    return counter;
  }
};
