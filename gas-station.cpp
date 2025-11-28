#include <vector>

class Solution {
public:
  int canCompleteCircuit(std::vector<int> &gas, std::vector<int> &cost) {
    const int N = gas.size();
    int total = 0, tank = 0, start = 0;

    for (int i = 0; i < N; ++i) {
      tank += gas[i] - cost[i];
      total += gas[i] - cost[i];

      if (tank < 0) {
        start = i + 1;
        tank = 0;
      }
    }

    return (total >= 0) ? start : -1;
  }
};
