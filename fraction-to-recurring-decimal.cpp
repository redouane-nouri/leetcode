#include <cstdlib>
#include <string>
#include <unordered_map>

class Solution {
public:
  std::string fractionToDecimal(int numerator, int denominator) {
    if (numerator == 0)
      return "0";

    std::string res;
    if ((numerator < 0) ^ (denominator < 0))
      res.push_back('-');

    long long n = std::llabs(numerator), d = std::llabs(denominator), r = n % d;
    res += std::to_string(n / d);

    if (r == 0)
      return res;

    res.push_back('.');

    std::unordered_map<long long, int> rPosMap;
    while (r != 0) {
      if (rPosMap.count(r)) {
        res.insert(rPosMap[r], "(");
        res.push_back(')');
        break;
      }

      rPosMap[r] = res.size();
      r *= 10;
      res += std::to_string(r / d);
      r %= d;
    }

    return res;
  }
};
