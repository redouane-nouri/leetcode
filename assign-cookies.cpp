#include <algorithm>
#include <vector>

class Solution {
public:
  int findContentChildren(std::vector<int> &g, std::vector<int> &s) {
    std::sort(g.begin(), g.end());
    std::sort(s.begin(), s.end());

    int n = g.size(), m = s.size(), children = 0, cookies = 0;

    while (children < n && cookies < m) {
      if (g[children] <= s[cookies])
        ++children;

      ++cookies;
    }

    return children;
  }
};
