#include <climits>

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
  long long prev;

  bool isValid(TreeNode *n) {
    if (!n)
      return true;

    if (!isValid(n->left))
      return false;

    if (n->val <= prev)
      return false;

    prev = n->val;
    return isValid(n->right);
  }

public:
  bool isValidBST(TreeNode *root) {
    prev = LLONG_MIN;
    return isValid(root);
  }
};
