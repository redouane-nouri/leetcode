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
  std::vector<std::vector<int>> res;
  std::vector<int> path;
  int targetSum, currSum = 0;

  void dfs(TreeNode *node) {
    if (!node)
      return;

    path.push_back(node->val);
    currSum += node->val;

    if (!node->left && !node->right && currSum == targetSum) {
      res.push_back(path);
    } else {
      dfs(node->left);
      dfs(node->right);
    }

    path.pop_back();
    currSum -= node->val;
  }

public:
  std::vector<std::vector<int>> pathSum(TreeNode *root, int targetSum) {
    this->targetSum = targetSum;
    dfs(root);
    return res;
  }
};
