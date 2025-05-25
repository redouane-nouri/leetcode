#include <string>
class Solution {
public:
  std::string convertToTitle(int columnNumber) {
    std::string res = "";
    char letter;
    int r;

    while (columnNumber > 0) {
      columnNumber--;
      r = columnNumber % 26;
      letter = 'A' + r;
      res = letter + res;
      columnNumber /= 26;
    }

    return res;
  }
};
