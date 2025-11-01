#include <unordered_set>
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
  ListNode *modifiedList(std::vector<int> &nums, ListNode *head) {
    std::unordered_set<int> numsSet(nums.begin(), nums.end());
    ListNode dummy(0, head), *prev = &dummy;

    while (head) {
      if (numsSet.count(head->val)) {
        prev->next = head->next;
      } else {
        prev = head;
      }

      head = head->next;
    }

    return dummy.next;
  }
};
