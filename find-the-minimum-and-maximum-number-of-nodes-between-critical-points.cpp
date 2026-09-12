/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  vector<int> nodesBetweenCriticalPoints(ListNode *head) {
    int i = 1, lastCrit = 0, mn = INT_MAX, mx = 0;
    ListNode *prev = head;
    head = head->next;

    while (head && head->next) {
      if (prev->val < head->val && head->next->val < head->val ||
          prev->val > head->val && head->next->val > head->val) {

        if (lastCrit) {
          mn = min(mn, i - lastCrit);
          mx += i - lastCrit;
        }

        lastCrit = i;
      }

      prev = head;
      head = head->next;
      ++i;
    }

    if (!mx)
      return {-1, -1};

    return {mn, mx};
  }
};
