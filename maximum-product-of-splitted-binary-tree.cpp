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
  long long totalSum = 0, maxProd = 0;

  long long sumOf(TreeNode *node) {
    if (!node)
      return 0;

    return node->val + sumOf(node->left) + sumOf(node->right);
  }

  long long dfs(TreeNode *node) {
    if (!node)
      return 0;

    long long currSum = node->val + dfs(node->left) + dfs(node->right);
    maxProd = std::max(maxProd, (totalSum - currSum) * currSum);
    return currSum;
  }

public:
  int maxProduct(TreeNode *root) {
    totalSum = sumOf(root);
    dfs(root);
    return maxProd % 1'000'000'007;
  }
};
