struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *rotateRight(ListNode *head, int k) {
    if (!head || !head->next)
      return head;

    int listLength = 1, tailPosition;
    ListNode *tmp = head, *newHead, *lastNode;

    while (tmp->next) {
      ++listLength;
      tmp = tmp->next;
    }

    tailPosition = listLength - (k % listLength);

    if (tailPosition == listLength)
      return head;

    lastNode = tmp;
    tmp = head;

    for (int i = 1; i < tailPosition; ++i)
      tmp = tmp->next;

    newHead = tmp->next;
    tmp->next = nullptr;
    lastNode->next = head;

    return newHead;
  }
};
