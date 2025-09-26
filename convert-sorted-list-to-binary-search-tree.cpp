struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
  ListNode *curr;

  TreeNode *build(int n) {
    if (n == 0)
      return nullptr;

    TreeNode *l = build(n / 2);

    TreeNode *treeNode = new TreeNode(curr->val);
    treeNode->left = l;
    curr = curr->next;

    treeNode->right = build(n - n / 2 - 1);

    return treeNode;
  }

public:
  TreeNode *sortedListToBST(ListNode *head) {
    curr = head;
    int n = 0;

    while (head) {
      head = head->next;
      ++n;
    }

    return build(n);
  }
};
