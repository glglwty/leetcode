#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
class Solution {
public:
    int shortestDistance(const std::vector<std::vector<int>>& grid) {
      constexpr std::pair<int, int> ds[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
      auto move = [](const std::pair<int, int>& s, const std::pair<int, int>& delta) -> std::pair<int, int> {
        return {s.first + delta.first, s.second + delta.second};
      };
      auto valid = [&grid](const std::pair<int, int>& p) {
        return p.first >= 0 && p.second >= 0 && p.first < grid.size() && p.second < grid[0].size();
      };
      std::vector<std::vector<int>> distance(grid.size(), std::vector<int>(grid[0].size(), 0));
      std::vector<std::vector<int>> current_distance(grid.size(), std::vector<int>(grid[0].size(), 0));
      auto convert2d = [](std::vector<std::vector<int>>& arr){
        return [&arr] (const std::pair<int, int>& p) -> int& {
          return arr[p.first][p.second];
        };
      };
      auto convert2dc = [](const std::vector<std::vector<int>>& arr){
        return [&arr] (const std::pair<int, int>& p) -> int {
          return arr[p.first][p.second];
        };
      };
      auto g = convert2dc(grid);
      auto cd = convert2d(current_distance);
      std::queue<std::pair<int, int>> q;
      for (int i = 0; i < grid.size(); i ++) {
        for (int j = 0; j < grid[0].size(); j ++) {
          if (grid[i][j] == 1) {
            for (auto& cd_row : current_distance) {
              std::fill(cd_row.begin(), cd_row.end(), 0);
            }
            for (q.emplace(i, j); !q.empty(); q.pop()) {
              auto& f = q.front();
              for (auto& d : ds) {
                auto t = move(f, d);
                if (valid(t) && cd(t) == 0 && g(t) == 0) {
                  cd(t) = cd(f) + 1;
                  q.push(t);
                }
              }
            }
            for (int ii = 0; ii < grid.size(); ii ++) {
              for (int jj = 0; jj < grid[0].size(); jj ++) {
                if (current_distance[ii][jj] <= 0) {
                  distance[ii][jj] = -1;
                } else if (distance[ii][jj] >= 0) {
                  distance[ii][jj] += current_distance[ii][jj];
                }
              }
            }
          }
        }
      }
      int minimum = std::numeric_limits<int>::max();
      for (auto& d_row : distance) {
        for (auto d : d_row) {
          if (d > 0 && d < minimum) {
            minimum = d;
          }
        }
      }
      if (minimum == std::numeric_limits<int>::max()) {
        return -1;
      } else {
        return minimum;
      }
    }
};
int main() {
  std::cout << Solution().shortestDistance({
    {1, 0, 2, 0, 1},
    {0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0}
  }) << std::endl;
  return 0;
}
