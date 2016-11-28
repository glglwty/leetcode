#include <iostream>
#include <algorithm>
#include <vector>
class Solution {
public:
  int longestIncreasingPath(const std::vector<std::vector<int>>& matrix) {
    if (matrix.empty()) {
      return 0;
    }
    std::vector<std::tuple<int, int, int>> elems;
    for (int i = 0; i < matrix.size(); i ++) {
      for (int j = 0; j < matrix[i].size(); j ++) {
          elems.emplace_back(matrix[i][j], i, j);
      }
    }
    int directions[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    auto valid = [&](int x, int y) {
      return x >= 0 && y >= 0 && x < matrix.size() && y < matrix[0].size();
    };
    std::vector<std::vector<int>> length(matrix.size(), std::vector<int>(matrix[0].size(), 1));
    sort(elems.begin(), elems.end());
    int result = 0;
    for (auto& tup : elems) {
      auto x = std::get<1>(tup);
      auto y = std::get<2>(tup);
      for (int d = 0; d < 4; d ++) {
        auto xprev = x + directions[d][0];
        auto yprev = y + directions[d][1];
        if (valid(xprev, yprev) && matrix[xprev][yprev] < matrix[x][y]) {
          length[x][y] = std::max(length[x][y], length[xprev][yprev] + 1);
        }
      }
      result = std::max(result, length[x][y]);
    }
    return result;
  }
};
int main() {
  std::cout << Solution().longestIncreasingPath(
    {
      {9,9,4},
      {6,6,8},
      {2,1,1}
    }
  ) << Solution().longestIncreasingPath(
    {
      {3,4,5},
      {3,2,6},
      {2,2,1}
    }
  ) << std::endl;
  return 0;
}
