#include <string>

class Solution {
public:
  int canBeTypedWords(std::string text, std::string brokenLetters) {
    bool brokenChars[26] = {false}, idTypeable = true;

    for (char &c : brokenLetters)
      brokenChars[c - 'a'] = true;

    text.push_back(' ');

    int res = 0;
    for (char &c : text) {
      if (c == ' ') {
        if (idTypeable)
          ++res;
        idTypeable = true;
      } else if (brokenChars[c - 'a']) {
        idTypeable = false;
      }
    }

    return res;
  }
};
