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

class BSTIterator {
  stack<TreeNode *> st;

  void pushLeft(TreeNode *node) {
    while (node) {
      st.push(node);
      node = node->left;
    }
  }

public:
  BSTIterator(TreeNode *root) { pushLeft(root); }

  int next() {
    auto tmp = st.top();
    st.pop();
    pushLeft(tmp->right);
    return tmp->val;
  }

  bool hasNext() { return !st.empty(); }
};
