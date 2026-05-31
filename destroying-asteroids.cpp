/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
      sort(steroids.begin(), ateroid.end());
      long long m = mass;

      for(int &a: asteroids){
        if(a > m)
          return false;

        m += a;
      }

      return true;
    }
};
