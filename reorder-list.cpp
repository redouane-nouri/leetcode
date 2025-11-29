struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  void reorderList(ListNode *head) {
    if (!head->next)
      return;

    ListNode *s = head, *f = head;

    while (f->next && f->next->next) {
      s = s->next;
      f = f->next->next;
    }

    ListNode *p = nullptr;
    f = s->next;
    s->next = nullptr;

    while (f) {
      ListNode *n = f->next;
      f->next = p;
      p = f;
      f = n;
    }

    s = head;
    while (p) {
      ListNode *sn = s->next, *pn = p->next;
      s->next = p;
      p->next = sn;
      s = sn;
      p = pn;
    }
  }
};
