#include <cmath>
#include <vector>

class Solution {
  constexpr static float EPS = 1e-4f;

  bool build(std::vector<float> &cards) {
    int n = cards.size();

    if (n == 1)
      return std::fabs(cards[0] - 24) < EPS;

    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        std::vector<float> remain;

        for (int k = 0; k < n; ++k)
          if (k != i && k != j)
            remain.push_back(cards[k]);

        std::vector<float> possibleValues = {
            cards[i] + cards[j], cards[i] - cards[j], cards[j] - cards[i],
            cards[i] * cards[j]};

        if (cards[j] != 0)
          possibleValues.push_back(cards[i] / cards[j]);
        if (cards[i] != 0)
          possibleValues.push_back(cards[j] / cards[i]);

        for (float v : possibleValues) {
          remain.push_back(v);
          if (build(remain))
            return true;
          remain.pop_back();
        }
      }
    }

    return false;
  }

public:
  bool judgePoint24(std::vector<int> &cards) {
    std::vector<float> fCards(cards.begin(), cards.end());
    return build(fCards);
  }
};
