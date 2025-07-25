#include <algorithm>
#include <string>

class Solution {
public:
  std::string toHex(int num) {
    std::string hexStr;
    constexpr char hexChars[] = "0123456789abcdef";
    unsigned int uNum = static_cast<unsigned int>(num);

    do {
      hexStr.push_back(hexChars[0x0000000f & uNum]);
      uNum >>= 4;
    } while (uNum != 0);

    std::reverse(hexStr.begin(), hexStr.end());
    return hexStr;
  }
};
