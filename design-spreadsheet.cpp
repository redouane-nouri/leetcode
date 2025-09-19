#include <string>
#include <vector>

class Spreadsheet {
  std::vector<std::vector<int>> sheet;

public:
  Spreadsheet(int rows) {
    sheet = std::vector<std::vector<int>>(rows, std::vector<int>(26, 0));
  }

  void setCell(std::string cell, int value) {
    sheet[std::stoi(cell.c_str() + 1) - 1][cell[0] - 'A'] = value;
  }

  void resetCell(std::string cell) {
    sheet[std::stoi(cell.c_str() + 1) - 1][cell[0] - 'A'] = 0;
  }

  int getValue(std::string formula) {
    int plusPos = formula.find('+'), res = 0;
    std::string x = formula.substr(1, plusPos - 1),
                y = formula.substr(plusPos + 1);

    if (x[0] >= 'A' && x[0] <= 'Z')
      res += sheet[std::stoi(x.c_str() + 1) - 1][x[0] - 'A'];
    else
      res += std::stoi(x);

    if (y[0] >= 'A' && y[0] <= 'Z')
      res += sheet[std::stoi(y.c_str() + 1) - 1][y[0] - 'A'];
    else
      res += std::stoi(y);

    return res;
  }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
