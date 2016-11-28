#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
class Solution {
public:
  int maxSumSubmatrix(const std::vector<std::vector<int>>& matrix, int upper_bound) {
    std::vector<std::vector<int>> prefix_sum(matrix.size(), std::vector<int>(matrix[0].size(), 0));
    for (int i = 0; i < matrix.size(); i ++) {
      int cur_row_sum = 0;
      for (int j = 0; j < matrix[0].size(); j ++) {
        cur_row_sum += matrix[i][j];
        prefix_sum[i][j] = (i == 0 ? 0 : prefix_sum[i - 1][j]) + cur_row_sum;
      }
    }
    auto sum = [&](int x0, int y0, int x1, int y1) {
      auto get = [&] (int x, int y) {
        if (x == -1 || y == -1) {
          return 0;
        }
        return matrix.size() > matrix[0].size() ? prefix_sum[y][x] : prefix_sum[x][y];
      };
      return get(x1, y1) - get(x0 - 1, y1) - get(x1, y0 - 1) + get(x0 - 1, y0 - 1);
    };
    std::pair<int, int> dim = std::minmax(matrix.size(), matrix[0].size());
    int result = std::numeric_limits<int>::min();
    for (int i = 0; i < dim.first; i ++) {
      for (int j = i; j < dim.first; j ++) {
        std::set<int> s;
        s.insert(0);
        for (int k = 0; k < dim.second; k ++) {
          auto k_sum = sum(i, 0, j, k);
          auto it = s.lower_bound(k_sum - upper_bound);
          if (it != s.end()) {
            result = std::max(result, k_sum - *it);
          }
          s.insert(k_sum);
        }
      }
    }
    return result;
  }
};
int main() {
  std::cout << Solution().maxSumSubmatrix({
    {1,  0, 1},
    {0, -2, 3}
  },2);
  return 0;
}
