struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  bool isPalindrome(ListNode *head) {
    ListNode *slow = head, *fast = head->next;

    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    ListNode *prev = nullptr, *curr = slow->next;

    while (curr) {
      ListNode *next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }

    while (prev) {
      if (head->val != prev->val)
        return false;

      head = head->next;
      prev = prev->next;
    }

    return true;
  }
};
