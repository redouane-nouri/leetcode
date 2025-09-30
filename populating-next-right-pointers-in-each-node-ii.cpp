class Node {
public:
  int val;
  Node *left;
  Node *right;
  Node *next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}

  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

  Node(int _val, Node *_left, Node *_right, Node *_next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
  Node *connect(Node *root) {
    if (root) {
      Node *c = root;

      while (c) {
        Node d(0), *t = &d;

        while (c) {
          if (c->left) {
            t->next = c->left;
            t = t->next;
          }

          if (c->right) {
            t->next = c->right;
            t = t->next;
          }

          c = c->next;
        }

        c = d.next;
      }
    }

    return root;
  }
};
