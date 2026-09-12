/**
 * @author Redouane Nouri
 */

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
  int ans = 0;
  pair<int, int> postOrder(TreeNode *root) {
    if (!root)
      return {0, 0};

    auto l = postOrder(root->left), r = postOrder(root->right);

    int sum = root->val + l.first + r.first, count = l.second + r.second + 1;

    if (root->val == sum / count)
      ++ans;

    return {sum, count};
  };

public:
  int averageOfSubtree(TreeNode *root) {
    postOrder(root);

    return ans;
  }
};
