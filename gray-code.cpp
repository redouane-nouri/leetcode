#include <vector>

class Solution {
public:
  std::vector<int> grayCode(int n) {
    int sz = 1 << n;
    std::vector<int> res;
    res.reserve(sz);

    for (int i = 0; i < sz; ++i)
      res.push_back(i ^ (i >> 1));

    return res;
  }
};
