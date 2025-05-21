#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  TreeNode *sortedArrayToBST(std::vector<int> &nums) {
    return this->generateTree(nums, 0, nums.size() - 1);
  }

private:
  TreeNode *generateTree(std::vector<int> &nums, int left, int right) {
    if (left > right) {
      return nullptr;
    }

    int mid = left + (right - left) / 2;
    TreeNode *node = new TreeNode(nums[mid]);

    node->left = generateTree(nums, left, mid - 1);
    node->right = generateTree(nums, mid + 1, right);

    return node;
  }
};
