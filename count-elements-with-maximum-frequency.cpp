#include <algorithm>
#include <vector>

class Solution {
public:
  int maxFrequencyElements(std::vector<int> &nums) {
    int freq[101] = {0};

    for (int &n : nums)
      ++freq[n];

    int mx = 0, res = 0;

    for (int i = 1; i < 101; ++i)
      if (freq[i] > mx)
        mx = res = freq[i];
      else if (freq[i] == mx)
        res += mx;

    return res;
  }
};
