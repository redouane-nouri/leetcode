#include <bits/stdc++.h>
using namespace std;
class Solution {
  multiset<int> minMs, restMs;
  int maxSz;
  long long sum = 0;
  void add(const int &x) {
    if (minMs.size() < maxSz) {
      minMs.insert(x);
      sum += x;
    } else {
      auto largetsMinIt = --minMs.end();
      if (*largetsMinIt <= x) {
        restMs.insert(x);
      } else {
        sum -= *largetsMinIt;
        restMs.insert(*largetsMinIt);
        minMs.erase(largetsMinIt);
        minMs.insert(x);
        sum += x;
      }
    }
  }
  void erase(const int &x) {
    auto it = minMs.find(x);
    if (it == minMs.end()) {
      restMs.erase(restMs.find(x));
    } else {
      minMs.erase(it);
      sum -= x;
      minMs.insert(*restMs.begin());
      sum += *restMs.begin();
      restMs.erase(restMs.begin());
    }
  }

public:
  long long minimumCost(vector<int> &nums, int k, int dist) {
    long long minSum = 0;
    const int N = nums.size();
    maxSz = k - 1;
    for (int i = 1; i <= dist + 1; ++i)
      add(nums[i]);
    long long ans = sum;
    for (int i = dist + 2; i < N; ++i)
      add(nums[i]), erase(nums[i - dist - 1]), ans = min(ans, sum);
    return ans + nums[0];
  }
};
