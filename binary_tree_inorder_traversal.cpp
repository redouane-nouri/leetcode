
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
  std::vector<int> inorderTraversal(TreeNode *root) {
    std::vector<int> res;
    TreeNode *curr = root, *pred;

    // Morris inorder traversal
    while (curr) {
      if (!curr->left) {
        // No left child, add curr val to res and go right
        res.push_back(curr->val);
        curr = curr->right;
      } else {
        pred = curr->left;
        // the predecessor is the rightmost node of the left subtree of curr
        while (pred->right && pred->right != curr) {
          pred = pred->right;
        }

        // first visit create a link (bookmark) from pred to curr and go left
        if (!pred->right) {
          pred->right = curr;
          curr = curr->left;
        } else {
          // second visit we have finished the left subtree of curr, remove the
          // link, add curr val to res, and go right
          pred->right = nullptr;
          res.push_back(curr->val);
          curr = curr->right;
        }
      }
    }

    return res;
  }
};
