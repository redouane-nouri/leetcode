/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
      vector<int> l, e, g;
      l.reserve(nums.size());

      for(int& num: nums)
        if(num < pivot)
          l.push_back(num);
        else if (num > pivot)
          g.push_back(num);
        else
          e.push_back(num);

      l.insert(l.end(), e.begin(), e.end());
      l.insert(l.end(), g.begin(), g.end());

      return l;
    }
};
