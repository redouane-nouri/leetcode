struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *listA = headA, *listB = headB;

    while (listA != listB) {
      listA = listA ? listA->next : headB;
      listB = listB ? listB->next : headA;
    }

    return listA;
  }
};
