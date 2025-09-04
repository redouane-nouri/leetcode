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
  TreeNode *f = nullptr, *s = nullptr, *p = nullptr;

  void search(TreeNode *n) {
    if (!n)
      return;

    search(n->left);

    if (p && n->val <= p->val) {
      if (!f)
        f = p;
      s = n;
    }

    p = n;
    search(n->right);
  }

public:
  void recoverTree(TreeNode *root) {
    search(root);
    f->val ^= s->val;
    s->val ^= f->val;
    f->val ^= s->val;
  }
};
