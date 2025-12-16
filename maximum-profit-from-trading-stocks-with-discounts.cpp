#include <algorithm>
#include <tuple>
#include <unordered_map>
#include <vector>

class Solution {
  std::vector<std::vector<int>> bossEmployees;
  std::vector<int> *p, *f;
  int bdg;

  std::tuple<std::vector<int>, std::vector<int>, int> dfs(int u) {
    std::vector<int> omitDP(bdg + 1, 0), purchaseDP(bdg + 1, 0),
        subOmitDP(bdg + 1, 0), subPurchaseDP(bdg + 1, 0);
    int &cost = (*p)[u], &sell = (*f)[u], halfCost = cost / 2, maxBudget = cost;

    for (auto &v : bossEmployees[u]) {
      auto [childOmitDp, childPurchaseDp, childMaxBudget] = dfs(v);
      maxBudget += childMaxBudget;

      for (int b = bdg; b >= 0; --b) {
        for (int subBdg = 0; subBdg <= std::min(childMaxBudget, b); ++subBdg) {
          subOmitDP[b] = std::max(subOmitDP[b],
                                  subOmitDP[b - subBdg] + childOmitDp[subBdg]);
          subPurchaseDP[b] =
              std::max(subPurchaseDP[b],
                       subPurchaseDP[b - subBdg] + childPurchaseDp[subBdg]);
        }
      }
    }

    for (int b = 0; b <= bdg; ++b) {
      omitDP[b] = purchaseDP[b] = subOmitDP[b];

      if (b >= cost)
        omitDP[b] = std::max(omitDP[b], subPurchaseDP[b - cost] + sell - cost);

      if (b >= halfCost)
        purchaseDP[b] = std::max(purchaseDP[b],
                                 subPurchaseDP[b - halfCost] + sell - halfCost);
    }

    return {omitDP, purchaseDP, maxBudget};
  }

public:
  int maxProfit(int n, std::vector<int> &present, std::vector<int> &future,
                std::vector<std::vector<int>> &hierarchy, int budget) {
    bossEmployees.resize(n);
    bdg = budget;
    p = &present;
    f = &future;

    for (auto &h : hierarchy)
      bossEmployees[h[0] - 1].push_back(h[1] - 1);

    return std::get<0>(dfs(0))[budget];
  }
};
