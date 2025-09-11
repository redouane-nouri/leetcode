#include <unordered_set>
#include <vector>

class Solution {
public:
  int minimumTeachings(int n, std::vector<std::vector<int>> &languages,
                       std::vector<std::vector<int>> &friendships) {
    std::vector<std::unordered_set<int>> uls;
    uls.reserve(languages.size());

    for (std::vector<int> &ls : languages)
      uls.emplace_back(ls.begin(), ls.end());

    std::unordered_set<int> ut;

    for (std::vector<int> &f : friendships) {
      int &u = f[0], &v = f[1];
      bool cc = false;

      for (int &lu : languages[u - 1]) {
        if (uls[v - 1].count(lu)) {
          cc = true;
          break;
        }
      }

      if (!cc) {
        ut.insert(u - 1);
        ut.insert(v - 1);
      }
    }

    std::vector<int> lfreq(n);

    for (const int &u : ut) {
      for (int &l : languages[u])
        ++lfreq[l - 1];
    }

    int res = 0;

    for (int &f : lfreq)
      if (res < f)
        res = f;

    return ut.size() - res;
  }
};
