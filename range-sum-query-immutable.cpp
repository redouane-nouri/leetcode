#include <vector>

class NumArray {
private:
  std::vector<int> sums;

public:
  NumArray(std::vector<int> &nums) {
    int sz = nums.size();
    this->sums.resize(sz + 1, 0);

    for (int i = 0; i < sz; ++i) {
      this->sums[i + 1] = this->sums[i] + nums[i];
    }
  }

  int sumRange(int left, int right) {
    return this->sums[right + 1] - this->sums[left];
  }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
