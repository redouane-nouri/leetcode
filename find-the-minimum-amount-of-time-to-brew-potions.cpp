#include <algorithm>
#include <vector>

class Solution {
public:
  long long minTime(std::vector<int> &skill, std::vector<int> &mana) {
    int n = skill.size(), m = mana.size(), sumSkills = 0;
    long long prevDoneTime;

    for (int &s : skill) {
      sumSkills += s;
    }

    prevDoneTime = 1LL * sumSkills * mana[0];

    for (int j = 1; j < m; ++j) {
      long long prevPDoneTime = prevDoneTime;
      for (int i = n - 2; i >= 0; --i) {
        prevPDoneTime -= skill[i + 1] * mana[j - 1];
        prevDoneTime =
            std::max(prevPDoneTime, prevDoneTime - skill[i] * mana[j]);
      }

      prevDoneTime += 1LL * sumSkills * mana[j];
    }

    return prevDoneTime;
  }
};
