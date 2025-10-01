class Solution {
public:
  int numWaterBottles(int numBottles, int numExchange) {
    int res = numBottles, empty = numBottles;

    while (empty >= numExchange) {
      int newB = empty / numExchange;
      res += newB;
      empty = empty % numExchange + newB;
    }

    return res;
  }
};
