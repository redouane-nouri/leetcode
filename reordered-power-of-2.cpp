#include <algorithm>
#include <vector>
class Solution {
  void fillFreq(int n, std::vector<int> &freq) {
    while (n != 0) {
      ++freq[n % 10];
      n /= 10;
    }
  }

public:
  bool reorderedPowerOf2(int n) {
    std::vector<int> freq(10, 0), powerOf2Freq(10);

    fillFreq(n, freq);

    unsigned int powerOf2 = 1;

    for (int i = 0; i < 30; ++i) {
      std::fill(powerOf2Freq.begin(), powerOf2Freq.end(), 0);
      fillFreq(powerOf2, powerOf2Freq);

      if (std::equal(freq.begin(), freq.end(), powerOf2Freq.begin(),
                     powerOf2Freq.end()))
        return true;

      powerOf2 <<= 1;
    }

    return false;
  }
};
