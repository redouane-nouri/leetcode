#include <bits/stdc++.h>

using namespace std;

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
  vector<int> nodes;

  void inorder(TreeNode *node) {
    if (node) {
      inorder(node->left);
      nodes.push_back(node->val);
      inorder(node->right);
    }
  }

  TreeNode *buildBST(int l, int r) {
    if (l > r)
      return nullptr;
    int m = l + (r - l >> 1);
    TreeNode *node = new TreeNode(nodes[m]);
    node->left = buildBST(l, m - 1);
    node->right = buildBST(m + 1, r);
    return node;
  }

public:
  TreeNode *balanceBST(TreeNode *root) {
    inorder(root);
    return buildBST(0, nodes.size() - 1);
  }
};
