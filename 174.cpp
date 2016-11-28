#include <iostream>
#include <algorithm>
#include <vector>
class Solution {
public:
  int calculateMinimumHP(const std::vector<std::vector<int>>& dungeon) {
    std::vector<int> f(dungeon[0].size(), -1);
    f.back() = 1;
    for (int i = dungeon.size() - 1; i >= 0; i --) {
      int right = -1;
      for (int j = dungeon[0].size() - 1; j >= 0; j --) {
        int r = std::numeric_limits<int>::max();
        if (right > 0) {
          r = std::max(1, right - dungeon[i][j]);
        }
        if (f[j] > 0) {
          r = std::min(r, std::max(1, f[j] - dungeon[i][j]));
        }
        right = f[j] = r;
      }
    }
    return f[0];
  }
};
int main() {
  std::cout << Solution().calculateMinimumHP({
    {-2, -3, 3},
    {-5, -10, 1},
    {10, 30, -5}
  }) << std::endl;
  return 0;
}
