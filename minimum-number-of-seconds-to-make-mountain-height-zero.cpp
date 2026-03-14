/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  long long minNumberOfSeconds(int mountainHeight, vector<int> &workerTimes) {
    auto isValid = [&workerTimes, &mountainHeight](long long t) {
      long long to = 0;

      for (int &wt : workerTimes) {
        double tt = (-1.0 + sqrt(1 + (8.0 * t / wt))) / 2.0;
        to += tt;

        if (to >= mountainHeight)
          return true;
      }

      return false;
    };

    long long l = 1;
    long long r =
        1LL * workerTimes[0] * mountainHeight * (mountainHeight + 1) >> 1;

    long long ans = 0;

    while (l < r) {
      long long m = l + ((r - l) >> 1);
      isValid(m) ? r = m : l = m + 1;
    }

    return l;
  }
};
