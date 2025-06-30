#include <stack>
#include <string>

class Solution {
public:
  int longestValidParentheses(std::string s) {
    int sLength = s.length(), mx = 0;
    std::stack<int> sk;
    sk.push(-1);

    for (int i = 0; i < sLength; ++i) {
      if (s[i] == '(') {
        sk.push(i);
      } else {
        sk.pop();
        if (sk.empty()) {
          sk.push(i);
        } else {
          if (mx < i - sk.top())
            mx = i - sk.top();
        }
      }
    }

    return mx;
  }
};
