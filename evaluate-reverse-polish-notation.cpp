#include <stack>
#include <string>
#include <vector>

class Solution {
public:
  int evalRPN(std::vector<std::string> &tokens) {
    std::stack<int> s;

    const auto isOperator = [](char o) -> bool {
      switch (o) {
      case '+':
      case '-':
      case '*':
      case '/':
        return true;

      default:
        return false;
      }
    };

    const auto calculate = [](char &o, int &od1, int &od2) -> int {
      switch (o) {
      case '+':
        return od1 + od2;

      case '-':
        return od1 - od2;

      case '*':
        return od1 * od2;

      default:
        return od1 / od2;
      }
    };

    for (auto &token : tokens) {
      if (!isOperator(token.back())) {
        s.push(std::stoi(token));
        continue;
      }

      int od1, od2;
      od2 = s.top();
      s.pop();
      od1 = s.top();
      s.pop();

      s.push(calculate(token[0], od1, od2));
    }

    return s.top();
  }
};
