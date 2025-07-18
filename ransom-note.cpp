#include <string>
#include <unordered_map>

class Solution {
public:
  bool canConstruct(std::string ransomNote, std::string magazine) {
    std::unordered_map<char, int> magazineMap;

    for (char c : magazine)
      magazineMap[c]++;

    for (char c : ransomNote) {
      if (--magazineMap[c] < 0)
        return false;
    }

    return true;
  }
};
