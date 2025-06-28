struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    if (!head || k == 1)
      return head;

    ListNode dummy, *explorer = &dummy, *prevGroupEnd = &dummy;

    dummy.next = head;

    while (explorer) {
      for (int i = 0; i < k; ++i) {
        explorer = explorer->next;
        if (!explorer)
          return dummy.next;
      }

      ListNode *prev, *curr, *nextEnd;

      curr = nextEnd = prevGroupEnd->next;
      prev = explorer->next;

      while (curr != nextEnd->next) {
        ListNode *tmp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = tmp;
      }

      prevGroupEnd->next = explorer;
      prevGroupEnd = explorer = nextEnd;
    }

    return dummy.next;
  }
};
