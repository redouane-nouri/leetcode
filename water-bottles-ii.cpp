class Solution {
public:
  int maxBottlesDrunk(int numBottles, int numExchange) {
    int res = numBottles, empty = numBottles;

    while (empty >= numExchange) {
      empty -= numExchange - 1;
      ++numExchange;
      ++res;
    }

    return res;
  }
};
