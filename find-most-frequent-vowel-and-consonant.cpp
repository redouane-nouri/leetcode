#include <string>

class Solution {
public:
  int maxFreqSum(std::string s) {
    int freq[26] = {0};

    for (char &ch : s)
      ++freq[ch - 'a'];

    auto isVowel = [](int &x) {
      switch (x) {
      case 0:
      case 4:
      case 8:
      case 14:
      case 20:
        return true;

      default:
        return false;
      }
    };
    int v = 0, c = 0;
    for (int i = 0; i < 26; ++i)
      if (isVowel(i)) {
        if (freq[i] > v)
          v = freq[i];
      } else {
        if (freq[i] > c)
          c = freq[i];
      }

    return v + c;
  }
};
