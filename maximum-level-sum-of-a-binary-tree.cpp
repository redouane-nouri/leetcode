#include <climits>
#include <queue>

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
  int maxLevelSum(TreeNode *root) {
    std::queue<TreeNode *> q;
    int minLevel = 0, currLevel = 0, maxSum = INT_MIN;

    q.push(root);

    while (!q.empty()) {
      ++currLevel;
      int sz = q.size(), currSum = 0;

      while (sz--) {
        TreeNode *node = q.front();
        currSum += node->val;
        q.pop();

        if (node->left)
          q.push(node->left);

        if (node->right)
          q.push(node->right);
      }

      if (currSum > maxSum) {
        maxSum = currSum;
        minLevel = currLevel;
      }
    }

    return minLevel;
  }
};
