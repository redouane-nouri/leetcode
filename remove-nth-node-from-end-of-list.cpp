struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *d = new ListNode(0, head), *s = d, *f = d;

    ++n;

    while (n) {
      f = f->next;
      --n;
    }

    while (f) {
      f = f->next;
      s = s->next;
    }

    s->next = s->next->next;

    return d->next;
  }
};
