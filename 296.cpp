#include <iostream>
#include <algorithm>
#include <vector>
#include <algorithm>
using std::vector;
class Solution {
public:
  int minTotalDistance(const vector<vector<int>>& grid) {
      std::vector<int> row, col;
      for (int i = 0; i < grid.size(); i ++) {
        for (int j = 0; j < grid[i].size(); j ++) {
          if (grid[i][j]) {
            row.push_back(i);
            col.push_back(j);
          }
        }
      }
      std::nth_element(row.begin(), row.begin() + row.size() / 2, row.end());
      std::nth_element(col.begin(), col.begin() + col.size() / 2, col.end());
      int x = row[row.size() / 2], y = col[col.size() / 2];

      int result = 0;
      for (int i = 0; i < grid.size(); i ++) {
        for (int j = 0; j < grid[i].size(); j ++) {
          if (grid[i][j]) {
            result += abs(i - x) + abs(j - y);
          }
        }
      }
      return result;
  }
};
int main() {
  std::cout << Solution().minTotalDistance({
    {1, 0, 0, 0, 1},
    {0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0}
  });

}
