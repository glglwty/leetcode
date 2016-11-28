#include <iostream>
#include <algorithm>
#include <vector>
class Solution {
public:
  int minPatches(const std::vector<int>& nums, int n) {
    int r = 0;
    for (long long i = 1, j = 0; i <= n;) {
      if (j == nums.size() || nums[j] > i) {
        r ++;
        i *= 2;
      } else {
        i += nums[j];
        j ++;
      }
    }
    return r;
  }
};
int main() {
  std::cout << Solution().minPatches({1, 2, 2}, 5) << std::endl;
  return 0;
}
