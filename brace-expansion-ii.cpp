/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<string> braceExpansionII(string expression) {
    stack<char> ops;
    stack<unordered_set<string>> sets;

    const auto operate = [&ops, &sets]() -> void {
      auto r = move(sets.top());
      sets.pop();
      auto &l = sets.top();

      const char c = ops.top();
      ops.pop();

      switch (c) {
      case '+':
        l.merge(r);
        break;

      case '*':
        unordered_set<string> mul;

        for (const auto &lstr : l)
          for (const auto &rstr : r)
            mul.insert(lstr + rstr);

        l = move(mul);
        break;
      }
    };

    const int N = expression.size();
    for (int i = 0; i < N; ++i) {
      const char &c = expression[i];

      switch (c) {
      case '{':
        if (i > 0 && (expression[i - 1] == '}' || isalpha(expression[i - 1])))
          ops.push('*');

        ops.push(c);
        break;

      case '}':
        while (ops.size() && ops.top() != '{')
          operate();

        ops.pop();
        break;

      case ',':
        while (ops.size() && ops.top() == '*')
          operate();

        ops.push('+');
        break;

      default:
        if (i > 0 && (expression[i - 1] == '}' || isalpha(expression[i - 1])))
          ops.push('*');

        sets.push({string(1, c)});
        break;
      }
    }

    while (ops.size())
      operate();

    vector<string> res;
    res.reserve(sets.top().size());

    move(sets.top().begin(), sets.top().end(), back_inserter(res));
    sort(res.begin(), res.end());

    return res;
  }
};
