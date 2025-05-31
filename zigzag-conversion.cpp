#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  string convert(string s, int numRows) {
    if (numRows == 1 || s.length() <= numRows)
      return s;

    vector<string> rows(numRows);
    int row = 0, dir = 1;

    for (char c : s) {
      rows[row] += c;

      // switch direction at top or bottom
      if (row == 0)
        dir = 1;
      else if (row == numRows - 1)
        dir = -1;

      row += dir;
    }

    string result;
    for (const string &r : rows)
      result += r;

    return result;
  }
};
