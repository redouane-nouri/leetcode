#include <queue>
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
public:
  std::vector<std::vector<int>> zigzagLevelOrder(TreeNode *root) {
    std::vector<std::vector<int>> res;

    if (!root)
      return res;

    std::queue<TreeNode *> q;
    q.push(root);

    int ri = 0;
    bool toLeft = true;

    while (!q.empty()) {
      int sz = q.size();
      res.emplace_back(sz);

      for (int i = 0; i < sz; ++i) {
        TreeNode *n = q.front();
        q.pop();

        if (toLeft)
          res[ri][i] = n->val;
        else
          res[ri][sz - i - 1] = n->val;

        if (n->left)
          q.push(n->left);

        if (n->right)
          q.push(n->right);
      }

      toLeft = !toLeft;

      ++ri;
    }

    return res;
  }
};
