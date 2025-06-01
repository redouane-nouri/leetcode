#include <algorithm>
#include <string>
#include <unordered_map>

std::unordered_map<int, std::string> iToR = {
    {1, "I"},   {4, "VI"},   {5, "V"},   {9, "XI"},  {10, "X"},
    {40, "LX"}, {50, "L"},   {90, "CX"}, {100, "C"}, {400, "DC"},
    {500, "D"}, {900, "MC"}, {1000, "M"}};

class Solution {
public:
  std::string intToRoman(int num) {
    int nbr;
    int placeValue = 1;
    std::string res;

    while (num) {
      nbr = num % (placeValue * 10);
      num = num - nbr;

      if (iToR.count(nbr)) {
        res += iToR[nbr];
      } else {
        while (!iToR.count(nbr) && nbr > 0) {
          res += iToR[placeValue];
          nbr -= placeValue;
        }

        if (iToR.count(nbr)) {
          res += iToR[nbr];
        }
      }

      placeValue *= 10;
    }

    std::reverse(res.begin(), res.end());

    return res;
  }
};
