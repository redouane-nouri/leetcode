#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> bestTower(vector<vector<int>> &towers, vector<int> &center,
                        int radius) {
    vector<int> ans = {-1, -1, -1};
    for (auto &t : towers) {
      int dis = std::abs(t[0] - center[0]) + std::abs(t[1] - center[1]);
      if (dis <= radius) {
        if (t[2] > ans[2]) {
          ans = t;
        } else if (t[2] == ans[2]) {
          if (t[0] < ans[0] || (t[0] == ans[0] && t[1] < ans[1])) {
            ans = t;
          }
        }
      }
    }
    return {ans[0], ans[1]};
  }
};
