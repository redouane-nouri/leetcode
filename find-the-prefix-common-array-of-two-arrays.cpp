/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
      const int N = A.size();
      bitset<51> a, b; 
      vector<int> c(N);

      for(int i = 0; i < N; ++i)
        a.set(A[i]), b.set(B[i]), c[i] = (a & b).count();

      return c;
    }
};
