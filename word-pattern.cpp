#include <sstream>
#include <string>
#include <unordered_map>

class Solution {
public:
  bool wordPattern(std::string pattern, std::string s) {
    std::unordered_map<char, std::string> charToStr;
    std::unordered_map<std::string, char> strToChar;
    std::istringstream iss(s);

    for (char c : pattern) {
      if (!(iss >> s))
        return false;

      if (charToStr.count(c)) {
        if (charToStr[c] != s)
          return false;
      } else {
        if (strToChar.count(s)) {
          if (strToChar[s] != c)
            return false;
        }
        charToStr[c] = s;
        strToChar[s] = c;
      }
    }

    return !(iss >> s);
  }
};
