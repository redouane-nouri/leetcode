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
  int countNodes(TreeNode *root) {
    if (!root)
      return 0;

    int h = getHeight(root);

    int l = 0, r = (1 << h) - 1;

    while (l <= r) {
      int m = l + (r - l) / 2;

      if (exists(root, m, h)) {
        l = m + 1;
      } else {
        r = m - 1;
      }
    }

    return (1 << h) - 1 + l;
  }

private:
  int getHeight(TreeNode *root) {
    int h = 0;

    while (root->left) {
      ++h;
      root = root->left;
    }

    return h;
  }

private:
  bool exists(TreeNode *root, int ix, int h) {
    int l = 0, r = (1 << h) - 1;

    for (int i = 0; i < h; ++i) {
      int m = l + (r - l) / 2;

      if (ix <= m) {
        root = root->left;
        r = m;
      } else {
        root = root->right;
        l = m + 1;
      }
    }

    if (!root)
      return false;

    return true;
  }
};
