struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  ListNode *split(ListNode *head, int step) {
    while (--step && head)
      head = head->next;

    if (!head)
      return nullptr;

    ListNode *newHead = head->next;
    head->next = nullptr;
    return newHead;
  }

  ListNode *merge(ListNode *a, ListNode *b) {
    ListNode dummy, *tail = &dummy;

    while (a && b) {
      a->val < b->val ? (tail->next = a, a = a->next)
                      : (tail->next = b, b = b->next);
      tail = tail->next;
    }

    tail->next = a ? a : b;
    return dummy.next;
  }

public:
  ListNode *sortList(ListNode *head) {
    if (!head || !head->next)
      return head;

    int n = 0;

    for (ListNode *p = head; p; p = p->next)
      ++n;

    ListNode dummy;
    dummy.next = head;

    for (int step = 1; step < n; step <<= 1) {
      ListNode *prev = &dummy, *curr = dummy.next;

      while (curr) {
        ListNode *l = curr, *r = split(l, step);
        curr = split(r, step);
        prev->next = merge(l, r);

        while (prev->next)
          prev = prev->next;
      }
    }

    return dummy.next;
  }
};
