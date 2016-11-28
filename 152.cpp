#include <iostream>
#include <vector>
#include <algorithm>
class Solution {
public:
  int maxProduct(const std::vector<int>& nums) {
    int result = nums[0], currentMax = nums[0], currentMin = nums[0];
    for (int i = 1; i < nums.size(); i ++) {
      int newMax = std::max(nums[i], std::max(currentMax * nums[i], currentMin * nums[i]));
      int newMin = std::min(nums[i], std::min(currentMax * nums[i], currentMin * nums[i]));
      currentMax = newMax;
      currentMin = newMin;
      result = std::max(result, newMax);
    }
    return  result;
  }
};
int main() {
  std::cout << Solution().maxProduct({2, 3, -2, 4});
  return 0;
}
