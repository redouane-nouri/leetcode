struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    if (!head)
      return nullptr;

    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
      fast = fast->next->next;
      slow = slow->next;

      if (fast == slow)
        break;
    }

    if (!fast || !fast->next)
      return nullptr;

    slow = head;
    while (slow != fast) {
      slow = slow->next;
      fast = fast->next;
    }

    return slow;
  }
};
