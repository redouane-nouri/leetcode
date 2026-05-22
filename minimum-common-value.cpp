/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
      const int N1 = nums1.size(), N2 = nums2.size();
      int i1 = 0, i2 = 0;

      while(i1 < N1 && i2 < N2){
        if(nums1[i1] == nums2[i2])
          return nums1[i1];
        else if(nums1[i1] < nums2[i2])
          ++i1;
        else
          ++i2;
      }

      return -1;
    }
};
