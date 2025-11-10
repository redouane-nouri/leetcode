#include <stack>
#include <vector>

class Solution {
public:
  int minOperations(std::vector<int> &nums) {
    std::stack<int> st;
    int ops = 0;

    for (int &num : nums) {
      while (!st.empty() && st.top() > num) {
        st.pop();
      }

      if (num != 0) {
        if (st.empty() || st.top() < num) {
          ++ops;
          st.push(num);
        }
      }
    }

    return ops;
  }
};
