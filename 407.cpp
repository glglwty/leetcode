#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
class Solution {
public:
  template<typename T> using greater_priority_queue =
    std::priority_queue<T, std::vector<T>, std::greater<T>>;
  int trapRainWater(const std::vector<std::vector<int>>& heightMap) {
    using coor_t = std::pair<int, int>;
    if (heightMap.size() == 0 || heightMap[0].size() == 0) {
      return 0;
    }
    auto w = heightMap[0].size(), h = heightMap.size();
    auto height = [&](const coor_t& coor) -> int {
      return heightMap[coor.first][coor.second];
    };
    std::vector<std::vector<int>> visited(h, std::vector<int>(w, 0));
    auto vis = [&](const coor_t& coor) -> int& {
      return visited[coor.first][coor.second];
    };
    greater_priority_queue<std::pair<int, coor_t>> q;
    auto enqueue = [&](int limit, const coor_t& coor) {
      q.emplace(limit, coor);
      vis(coor) = 1;
    };
    auto inbound = [w, h](const coor_t& coor) -> bool {
      return coor.first > 0 && coor.second > 0
        && coor.first < h && coor.second < w;
    };
    for (int i = 0; i < h; i ++) {
      enqueue(heightMap[i][0], {i, 0});
      enqueue(heightMap[i][w - 1], {i, w - 1});
    }
    for (int i = 1; i < w - 1; i ++) {
      enqueue(heightMap[0][i], {0, i});
      enqueue(heightMap[h - 1][i], {h - 1, i});
    }
    coor_t directions[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    auto move = [](const coor_t& a, const coor_t& b) -> coor_t {
      return {a.first + b.first, a.second + b.second};
    };
    int result = 0;
    while (!q.empty()) {
      auto lowest = q.top();
      q.pop();
      //std::cerr << lowest.first << ' ' << lowest.second.first << ' ' << lowest.second.second << std::endl;
      for (auto& d : directions) {
        auto target = move(lowest.second, d);
        if (inbound(target) && !vis(target)) {
          int watertop = std::max(lowest.first, height(target));
          result += watertop - height(target);
          enqueue(watertop, target);
        }
      }
    }
    return result;
  }
};
int main() {
  std::cout << Solution().trapRainWater({
    {1, 4, 3, 1, 3, 2},
    {3, 2, 1, 3, 2, 4},
    {2, 3, 3, 2, 3, 1}
  }) << std::endl;
  return 0;
}
