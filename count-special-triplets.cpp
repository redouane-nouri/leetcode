#include <unordered_map>
#include <vector>
class Solution {
public:
  int specialTriplets(std::vector<int> &nums) {
    const int MOD = 1'000'000'007;
    std::unordered_map<int, int> l, r;

    for (int &num : nums)
      r[num]++;

    int ans = 0;
    for (int &num : nums) {
      --r[num];

      int fl = l[num << 1], fr = r[num << 1];
      ans = (ans + (1LL * fl * fr)) % MOD;

      ++l[num];
    }

    return ans;
  }
};
