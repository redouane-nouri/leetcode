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
  std::vector<int> preorderTraversal(TreeNode *root) {
    std::vector<int> res;
    TreeNode *curr = root, *pred;

    // Morris preorder traversal
    while (curr) {
      if (!curr->left) {
        res.push_back(curr->val);
        curr = curr->right;
      } else {
        pred = curr->left;

        while (pred->right && pred->right != curr) {
          pred = pred->right;
        }

        if (!pred->right) {
          pred->right = curr;
          res.push_back(curr->val);
          curr = curr->left;
        } else {
          pred->right = nullptr;
          curr = curr->right;
        }
      }
    }

    return res;
  }
};
