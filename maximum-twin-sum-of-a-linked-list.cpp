/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  int pairSum(ListNode *head) {
    ListNode *s = head, *f = head;

    while (f && f->next)
      s = s->next, f = f->next->next;

    ListNode *p = nullptr;
    while (s) {
      ListNode *n = s->next;
      s->next = p;
      p = s;
      s = n;
    }

    int ans = 0;
    while (p) {
      ans = max(ans, p->val + head->val);
      p = p->next, head = head->next;
    }

    return ans;
  }
};
