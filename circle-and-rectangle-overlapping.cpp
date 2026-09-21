/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1,
                    int x2, int y2) {
    int dis = 0;

    if (xCenter < x1)
      dis += pow(x1 - xCenter, 2);
    else if (xCenter > x2)
      dis += pow(x2 - xCenter, 2);

    if (yCenter < y1)
      dis += pow(y1 - yCenter, 2);
    else if (yCenter > y2)
      dis += pow(y2 - yCenter, 2);

    return dis <= radius * radius;
  }
};
