/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  double angleClock(int hour, int minutes) {
    if (hour == 12)
      hour = 0;

    double minAngle = minutes * 6.0, hourAngle = hour * 30.0 + minutes * 0.5,
           diff = abs(minAngle - hourAngle);

    return min(diff, 360.0 - diff);
  }
};
