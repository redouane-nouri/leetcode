/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  bool isRectangleOverlap(vector<int> &rec1, vector<int> &rec2) {
    int &l1 = rec1[0], &b1 = rec1[1], &r1 = rec1[2], &t1 = rec1[3],
        &l2 = rec2[0], &b2 = rec2[1], &r2 = rec2[2], &t2 = rec2[3];

    return min(r1, r2) > max(l1, l2) && min(t1, t2) > max(b1, b2);
  }
};
