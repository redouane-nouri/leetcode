#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
  std::vector<std::vector<std::vector<TreeNode *>>> dp;
  std::vector<TreeNode *> empty;

  std::vector<TreeNode *> &build(int s, int e) {
    if (s > e)
      return empty;

    if (!dp[s][e].empty())
      return dp[s][e];

    dp[s][e].reserve(getCatalan(e - s + 1));

    for (int v = s; v <= e; ++v) {
      std::vector<TreeNode *> &rt = build(v + 1, e);
      std::vector<TreeNode *> &lt = build(s, v - 1);
      int rs = rt.size(), ls = lt.size();

      for (int li = 0; li < ls; ++li)
        for (int ri = 0; ri < rs; ++ri)
          dp[s][e].push_back(new TreeNode(v, lt[li], rt[ri]));
    }

    return dp[s][e];
  }

  int getCatalan(int n) {
    int C[9] = {0};
    C[0] = 1;

    for (int i = 1; i <= n; ++i)
      for (int j = 0; j < i; ++j)
        C[i] += C[j] * C[i - 1 - j];

    return C[n];
  }

public:
  std::vector<TreeNode *> generateTrees(int n) {
    empty = std::vector<TreeNode *>(1, nullptr);
    dp = std::vector<std::vector<std::vector<TreeNode *>>>(
        n + 1, std::vector<std::vector<TreeNode *>>(n + 1));
    return build(1, n);
  }
};
