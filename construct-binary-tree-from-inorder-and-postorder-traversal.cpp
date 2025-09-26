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
  std::vector<int> *postorder;
  int postPos;

  TreeNode *build(int l, int r) {
    if (l > r)
      return nullptr;

    TreeNode *node = new TreeNode((*postorder)[postPos--]);
    int inPos = inorderIndexMap[node->val];

    node->right = build(inPos + 1, r);
    node->left = build(l, inPos - 1);

    return node;
  }

public:
  TreeNode *buildTree(std::vector<int> &inorder, std::vector<int> &postorder) {
    this->postorder = &postorder;

    postPos = postorder.size() - 1;
    inorderIndexMap.reserve(postorder.size());

    for (int i = 0; i < inorder.size(); ++i)
      inorderIndexMap[inorder[i]] = i;

    return build(0, inorder.size() - 1);
  }
};
