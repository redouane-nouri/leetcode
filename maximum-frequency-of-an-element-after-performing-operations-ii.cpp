#include <algorithm>
#include <map>
#include <unordered_map>
#include <vector>

class Solution {
public:
  int maxFrequency(std::vector<int> &nums, int k, int numOperations) {
    std::unordered_map<int, int> freqs;
    std::map<int, int> ranges;

    freqs.reserve(numOperations);

    for (int &num : nums) {
      ++freqs[num];
      ranges[num] += 0;
      ranges[num - k] += 1;
      ranges[num + k + 1] -= 1;
    }

    int res = 1, adjustable = 0;

    for (auto &range : ranges) {
      adjustable += range.second;
      int freq = freqs.count(range.first) ? freqs[range.first] : 0;

      res = std::max(res, std::min(adjustable - freq, numOperations) + freq);
    }
    return res;
  }
};
