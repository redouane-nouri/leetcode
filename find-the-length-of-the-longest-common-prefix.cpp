/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
      unordered_set<int> prfxs;

      for(int &a: arr1)
        while(!prfxs.count(a) && a)
          prfxs.insert(a), a /= 10;

      int ans = 0;
      for(int &a: arr2){
        while(!prfxs.count(a) && a)
          a /= 10;

        if(a)
          ans = max(ans, (int)log10(a) + 1);
      }

      return ans;
    }
};
