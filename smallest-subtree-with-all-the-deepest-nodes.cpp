#include <utility>

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
  std::pair<TreeNode *, int> dfs(TreeNode *node) {
    if (!node)
      return {nullptr, 0};

    auto l = dfs(node->left), r = dfs(node->right);

    if (l.second > r.second)
      return {l.first, 1 + l.second};

    if (r.second > l.second)
      return {r.first, 1 + r.second};

    return {node, 1 + r.second};
  }

public:
  TreeNode *subtreeWithAllDeepest(TreeNode *root) { return dfs(root).first; }
};
