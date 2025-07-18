
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
  bool hasPathSum(TreeNode *root, int targetSum) {
    if (!root)
      return false;

    if (!root->left && !root->right) {
      return root->val == targetSum;
    }

    int remaining_sum = targetSum - root->val;

    return hasPathSum(root->left, remaining_sum) ||
           hasPathSum(root->right, remaining_sum);
  }
};
