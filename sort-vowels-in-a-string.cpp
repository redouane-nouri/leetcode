#include <algorithm>
#include <string>
#include <vector>

class Solution {
public:
  std::string sortVowels(std::string s) {
    int freq[11] = {0};

    auto vowelIndex = [](char &c) {
      switch (c) {
      case 'A':
        return 0;
      case 'E':
        return 1;
      case 'I':
        return 2;
      case 'O':
        return 3;
      case 'U':
        return 4;
      case 'a':
        return 5;
      case 'e':
        return 6;
      case 'i':
        return 7;
      case 'o':
        return 8;
      case 'u':
        return 9;
      default:
        return 10;
      }
    };

    for (char &c : s)
      ++freq[vowelIndex(c)];

    for (char &c : s) {
      if (vowelIndex(c) < 10) {
        for (int i = 0; i < 10; ++i) {
          if (freq[i]) {
            c = "AEIOUaeiou"[i];
            --freq[i];
            break;
          }
        }
      }
    }

    return s;
  }
};
