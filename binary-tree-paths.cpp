#include <string>
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
  std::vector<std::string> binaryTreePaths(TreeNode *root) {
    std::vector<std::string> res;
    std::string path = std::to_string(root->val);

    if (root->left || root->right) {
      if (root->left)
        discover(res, root->left, path);

      if (root->right)
        discover(res, root->right, path);
    } else {
      res.push_back(path);
    }

    return res;
  }

private:
  void discover(std::vector<std::string> &res, TreeNode *node,
                std::string path) {
    path += ("->" + std::to_string(node->val));

    if (!node->left && !node->right) {
      res.push_back(path);
      return;
    }

    if (node->left)
      discover(res, node->left, path);

    if (node->right)
      discover(res, node->right, path);
  }
};
