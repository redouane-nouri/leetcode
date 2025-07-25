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
  int sumOfLeftLeaves(TreeNode *root) {
    int sum = 0;
    dfs(root, sum, false);
    return sum;
  }

private:
  void dfs(TreeNode *node, int &sum, bool isLeftChild) {
    if (!node)
      return;

    if (!node->left && !node->right && isLeftChild) {
      sum += node->val;
      return;
    }

    dfs(node->left, sum, true);
    dfs(node->right, sum, false);
  }
};
