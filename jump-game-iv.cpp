/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
      const int N = arr.size();

      if(N <= 1)
        return 0;

      unordered_map<int, vector<int>> mp;

      for(int i = 0; i < N; ++i)
        mp[arr[i]].push_back(i);

      unordered_set<int> l, r;
      l.insert(0), r.insert(N-1);

      vector<bool> vs(N, false);
      vs[0] = true, vs[N-1]=true;

      int ans = 0;
      while(!l.empty()){
        if(l.size() > r.size())
          swap(l, r);

        unordered_set<int> n;

        for(const int &i: l){
          for(int &j: mp[arr[i]]){
            if(r.count(j))
              return ans + 1;

            if(!vs[j])
              n.insert(j), vs[j] = true;
          }

          mp[arr[i]].clear();

          if(r.count(i-1) || r.count(i+1))
            return ans + 1;

          if(i-1 >= 0 && !vs[i-1])
            n.insert(i-1), vs[i-1] = true;

          if(i+1 < N && !vs[i+1])
            n.insert(i+1), vs[i+1] = true;
        }

        ++ans;
        l = n;
      }

      return -1;
    }
};
