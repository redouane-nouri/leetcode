/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) { 
      const int N = nums.size();

      if(N == 1)
        return true;

      bool rotationFound = false;
      for(int i = 1; i < N; ++i){
        if(nums[i] < nums[i+1]){
          if(rotationFound)
            return false;

          rotationFound = true;
        }
      }

      if(nums[0] < nums[N-1] && rotationFound)
        return false;

      return true;
    }
};

