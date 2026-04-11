/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Robot {
  vector<vector<int>> path;
  vector<int> dirAtCell;
  int idx = 0, N;
  bool moved = false;

public:
  Robot(int width, int height) {
    for (int x = 0; x < width; ++x)
      path.push_back({x, 0}), dirAtCell.push_back(0);

    for (int y = 1; y < height; ++y)
      path.push_back({width - 1, y}), dirAtCell.push_back(1);

    for (int x = width - 2; x >= 0; --x)
      path.push_back({x, height - 1}), dirAtCell.push_back(2);

    for (int y = height - 2; y > 0; --y)
      path.push_back({0, y}), dirAtCell.push_back(3);

    dirAtCell[0] = 3;
    N = path.size();
  }

  void step(int num) {
    moved = true;
    idx = (idx + num) % N;
  }

  vector<int> getPos() { return path[idx]; }

  string getDir() {
    if (!moved)
      return "East";

    switch (dirAtCell[idx]) {
    case 0:
      return "East";

    case 1:
      return "North";

    case 2:
      return "West";

    default:
      return "South";
    }
  }
};
