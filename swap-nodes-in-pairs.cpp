struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *swapPairs(ListNode *head) {
    ListNode d(0, head), *p = &d;

    while (head && head->next) {
      p->next = head->next;
      head->next = head->next->next;
      p->next->next = head;

      p = head;
      head = head->next;
    }

    return d.next;
  }
};
