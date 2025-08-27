class Solution {
public:
  int numTrees(int n) {
    int C[20] = {0};
    C[0] = 1;

    for (int i = 1; i <= n; ++i)
      for (int j = 0; j < i; ++j)
        C[i] += C[j] * C[i - 1 - j];

    return C[n];
  }
};
