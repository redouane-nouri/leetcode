#include <unordered_map>
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
  std::unordered_map<int, int> inorderIndexMap;
  std::vector<int> *preorder;
  int prePos = 0;

  TreeNode *build(int l, int r) {
    if (l > r)
      return nullptr;

    TreeNode *node = new TreeNode((*preorder)[prePos++]);
    int inPos = inorderIndexMap[node->val];

    node->left = build(l, inPos - 1);
    node->right = build(inPos + 1, r);

    return node;
  }

public:
  TreeNode *buildTree(std::vector<int> &preorder, std::vector<int> &inorder) {
    this->preorder = &preorder;
    inorderIndexMap.reserve(inorder.size());

    for (int i = 0; i < inorder.size(); ++i)
      inorderIndexMap[inorder[i]] = i;

    return build(0, inorder.size() - 1);
  }
};
