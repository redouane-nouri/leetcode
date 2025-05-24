#include <algorithm>
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
  std::vector<int> postorderTraversal(TreeNode *root) {
    std::vector<int> res;
    TreeNode *curr, *pred;
    curr = root;

    while (curr) {
      if (!curr->right) {
        res.push_back(curr->val);
        curr = curr->left;
      } else {
        pred = curr->right;
        while (pred->left && pred->left != curr) {
          pred = pred->left;
        }

        if (!pred->left) {
          res.push_back(curr->val);
          pred->left = curr;
          curr = curr->right;
        } else {
          pred->left = nullptr;
          curr = curr->left;
        }
      }
    }

    std::reverse(res.begin(), res.end());
    return res;
  }
};
