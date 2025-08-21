#include <stack>
#include <vector>

class Solution {
public:
  int numSubmat(std::vector<std::vector<int>> &mat) {
    int m = mat.size(), n = mat[0].size(), res = 0;
    std::vector<int> h(n, 0);

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j)
        if (mat[i][j] == 0)
          h[j] = 0;
        else
          h[j]++;

      std::stack<int> s;
      std::vector<int> sum(n, 0);

      for (int j = 0; j < n; ++j) {
        while (!s.empty() && h[s.top()] >= h[j])
          s.pop();

        if (!s.empty()) {
          int top = s.top();
          sum[j] = sum[top] + h[j] * (j - top);
        } else {
          sum[j] = h[j] * (j + 1);
        }

        res += sum[j];
        s.push(j);
      }
    }

    return res;
  }
};
