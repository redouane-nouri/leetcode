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

/*
//Morris traversal solution
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
public:
  void recoverTree(TreeNode *root) {
    TreeNode *f = nullptr, *s = nullptr, *p = nullptr, *c = root, *pr;

    while (c) {
      if (!c->left) {
        if (p && p->val >= c->val) {
          if (!f)
            f = p;
          s = c;
        }
        p = c;
        c = c->right;
      } else {
        pr = c->left;
        while (pr->right && pr->right != c)
          pr = pr->right;

        if (!pr->right) {
          pr->right = c;
          c = c->left;
        } else {
          pr->right = nullptr;

          if (p->val >= c->val) {
            if (!f)
              f = p;
            s = c;
          }

          p = c;
          c = c->right;
        }
      }
    }

    f->val ^= s->val;
    s->val ^= f->val;
    f->val ^= s->val;
  }
};
*/
