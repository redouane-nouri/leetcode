#include <algorithm>

class Solution {
public:
  int maxDepth(TreeNode *root) {
    if (!root)
      return 0;
    return std::max(maxDepth(root->right), maxDepth(root->left)) + 1;
  }
};
