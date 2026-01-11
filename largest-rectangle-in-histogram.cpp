#include <algorithm>
#include <stack>
#include <vector>

class Solution {
public:
  int largestRectangleArea(std::vector<int> &heights) {
    heights.push_back(0);
    const int N = heights.size();
    int maxArea = 0;
    std::stack<int> s;

    for (int i = 0; i < N; ++i) {
      while (!s.empty() && heights[i] < heights[s.top()]) {
        int h = heights[s.top()];
        s.pop();
        int w = s.empty() ? i : i - s.top() - 1;
        maxArea = std::max(maxArea, h * w);
      }

      s.push(i);
    }

    return maxArea;
  }
};
