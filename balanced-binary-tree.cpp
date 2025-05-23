#include <algorithm>

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
  bool isBalanced(TreeNode *root) { return isBalancedHelper(root) != -1; }

private:
  int isBalancedHelper(TreeNode *root) {
    if (!root) {
      return 0;
    }

    int leftDepth = isBalancedHelper(root->left);
    if (leftDepth == -1) {
      return -1;
    }

    int rightDepth = isBalancedHelper(root->right);
    if (rightDepth == -1) {
      return -1;
    }

    if (std::abs(leftDepth - rightDepth) > 1) {
      return -1;
    }

    return std::max(leftDepth, rightDepth) + 1;
  }
};
