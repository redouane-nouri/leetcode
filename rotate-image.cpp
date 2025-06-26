#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  void rotate(vector<vector<int>> &matrix) {
    const int size = matrix.size();

    for (int i = 0; i < size - 1; ++i) {
      for (int j = i; j < size; ++j) {
        swap(matrix[i][j], matrix[j][i]);
      }
    }
    for (int i = 0; i < size; ++i) {
      reverse(matrix[i].begin(), matrix[i].end());
    }
  }
};
