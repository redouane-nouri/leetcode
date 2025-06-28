#include <queue>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *mergeKLists(std::vector<ListNode *> &lists) {
    auto compare = [](ListNode *a, ListNode *b) { return a->val > b->val; };
    std::priority_queue<ListNode *, std::vector<ListNode *>, decltype(compare)>
        pq(compare);

    for (ListNode *l : lists) {
      if (l) {
        pq.push(l);
      }
    }

    ListNode dummy(0), *tail = &dummy;

    while (!pq.empty()) {
      ListNode *top = pq.top();
      tail = tail->next = top;
      pq.pop();

      if (top->next) {
        pq.push(top->next);
      }
    }

    return dummy.next;
  }
};
