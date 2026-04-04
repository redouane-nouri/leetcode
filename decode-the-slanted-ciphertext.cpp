/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  string decodeCiphertext(string encodedText, const int rows) {
    const int C = encodedText.size() / rows;
    vector mat(rows, vector<char>(C));

    for (int i = 0; i < rows; ++i)
      for (int j = 0; j < C; ++j)
        mat[i][j] = encodedText[i * C + j];

    string ans;

    for (int j = 0; j < C; ++j)
      for (int i = 0; i < min(rows, C - j); ++i)
        ans.push_back(mat[i][j + i]);

    while (ans.size() && ans.back() == ' ')
      ans.pop_back();

    return ans;
  }
};
