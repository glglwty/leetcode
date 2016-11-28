#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
std::pair<int, int> operator + (
  const std::pair<int, int>& a,
  const std::pair<int, int>& b) {
  return {a.first + b.first, a.second + b.second};
}
class Solution {
public:
  int numIslands(std::vector<std::vector<char>>& grid) {
    int result = 0;
    for (int i = 0; i < grid.size(); i ++) {
      for (int j = 0; j < grid[0].size(); j ++) {
        if (grid[i][j] == '1') {
          grid[i][j] = '2';
          result ++;
          std::pair<int, int> directions[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
          std::queue<std::pair<int, int>> q;
          for (q.emplace(i, j); !q.empty(); q.pop()) {
            auto f = q.front();
            for (auto& direction : directions) {
              auto target = f + direction;
              if (target.first >= 0 && target.first < grid.size() &&
                  target.second >= 0 && target.second < grid[0].size() &&
                  grid[target.first][target.second] == '1') {
                grid[target.first][target.second] = '2';
                q.push(target);
              }
            }
          }
        }
      }
    }
    return result;
  }
};
int main() {
  std::vector<std::vector<char>> grid {
    {'1', '1', '0', '0', '0'},
    {'1', '1', '0', '0', '0'},
    {'1', '0', '1', '0', '0'},
    {'0', '0', '0', '1', '1'}
  };
  std::cout << Solution().numIslands(grid) << std::endl;;
  return 0;
}
