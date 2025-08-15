struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    ListNode dummy(0, head), *prev = &dummy, *tail, *nextN;

    for (int i = 1; i < left; ++i)
      prev = prev->next;

    tail = prev->next;

    for (int i = 0; i < right - left; ++i) {
      nextN = tail->next;
      tail->next = nextN->next;
      nextN->next = prev->next;
      prev->next = nextN;
    }

    return dummy.next;
  }
};
