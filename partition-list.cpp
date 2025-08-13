struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *partition(ListNode *head, int x) {
    ListNode dummy(0, head), *prev, *lastSorted;
    lastSorted = prev = &dummy;

    while (head) {
      if (head->val < x) {
        prev->next = head->next;
        head->next = lastSorted->next;
        lastSorted->next = head;
        lastSorted = head;
      }

      prev = head;
      head = head->next;
    }

    return dummy.next;
  }
};
