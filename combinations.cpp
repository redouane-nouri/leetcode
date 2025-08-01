#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> combine(int n, int k) {
    std::vector<std::vector<int>> res;
    std::vector<int> combination(k);

    combinations(res, combination, n, k);
    return res;
  }

private:
  void combinations(std::vector<std::vector<int>> &res,
                    std::vector<int> &combination, int n, int k) {
    if (k == 0) {
      res.push_back(combination);
      return;
    }

    for (int i = n; i > 0; --i) {
      combination[k - 1] = i;
      combinations(res, combination, i - 1, k - 1);
    }
  }
};
