#include <algorithm>
#include <stack>
#include <vector>

class Solution {
public:
  int maximalRectangle(std::vector<std::vector<char>> &matrix) {
    const int m = matrix.size(), n = matrix[0].size();
    int ans = 0;
    std::vector<int> heights(n + 1, 0);

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j)
        heights[j] = matrix[i][j] == '1' ? heights[j] + 1 : 0;

      std::stack<int> s;
      int maxArea = 0;

      for (int k = 0; k <= n; ++k) {
        while (!s.empty() && heights[k] < heights[s.top()]) {
          int h = heights[s.top()];
          s.pop();
          int w = s.empty() ? k : k - s.top() - 1;
          maxArea = std::max(maxArea, h * w);
        }

        s.push(k);
      }

      ans = std::max(ans, maxArea);
    }

    return ans;
  }
};
