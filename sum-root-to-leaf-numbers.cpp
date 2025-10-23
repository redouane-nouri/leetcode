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
  int res = 0;
  void dfs(TreeNode *node, int sum) {
    sum = sum * 10 + node->val;

    if (node->left || node->right) {
      if (node->right) {
        dfs(node->right, sum);
      }

      if (node->left) {
        dfs(node->left, sum);
      }
    } else {
      res += sum;
    }
  }

public:
  int sumNumbers(TreeNode *root) {
    dfs(root, 0);
    return res;
  }
};
