#include <vector>

class Solution {
  std::vector<std::vector<int>> adjacents;
  std::vector<int> *vals;
  int ans = 0, mod;

  int dfs(int curr, int parent) {
    int sum = (*vals)[curr] % mod;

    for (int &adjacent : adjacents[curr]) {
      if (adjacent != parent) {
        sum = (sum + dfs(adjacent, curr)) % mod;
      }
    }

    if (sum == 0)
      ++ans;

    return sum;
  }

public:
  int maxKDivisibleComponents(int n, std::vector<std::vector<int>> &edges,
                              std::vector<int> &values, int k) {
    vals = &values;
    mod = k;
    adjacents.assign(n, {});

    for (auto &edge : edges) {
      adjacents[edge[0]].push_back(edge[1]);
      adjacents[edge[1]].push_back(edge[0]);
    }

    dfs(0, -1);

    return ans;
  }
};
