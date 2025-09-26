#include <algorithm>
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
  std::vector<std::vector<int>> levelOrderBottom(TreeNode *root) {
    if (!root)
      return {};

    std::queue<TreeNode *> q;
    q.push(root);

    std::vector<std::vector<int>> res;
    while (!q.empty()) {
      int sz = q.size();
      res.emplace_back();

      while (sz) {
        TreeNode *f = q.front();
        q.pop();
        res.back().push_back(f->val);

        if (f->left)
          q.push(f->left);

        if (f->right)
          q.push(f->right);

        --sz;
      }
    }

    std::reverse(res.begin(), res.end());
    return res;
  }
};
