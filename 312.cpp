#include <iostream>
#include <algorithm>
#include <vector>
class Solution {
public:
  int maxCoins(const std::vector<int>& nums) {
    if (nums.size() == 0) {
      return 0;
    }
    std::vector<std::vector<int>> f(nums.size(), std::vector<int>(nums.size(), 0));
    for (int i = 0; i < nums.size(); i ++) {
      for (int j = 0; i + j < nums.size(); j ++) {
        for (int k = j; k <= i + j; k ++) {
          int cur = 0;
          if (k != j) {
            cur += f[k - j - 1][j];
          }
          if (k != i + j) {
            cur += f[i + j - k - 1][k + 1];
          }
          int l = (j == 0) ? 1 : nums[j - 1];
          int r = (i + j == nums.size() - 1) ? 1 : nums[i + j + 1];
          f[i][j] = std::max(f[i][j], cur + nums[k] * l * r);
        }
      }
    }
    return f[nums.size() - 1][0];
  }
};
int main() {
  std::cout << Solution().maxCoins({3, 1, 5, 8}) << std::endl;
  return 0;
}
