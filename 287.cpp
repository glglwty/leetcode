#include <iostream>
#include <algorithm>
#include <vector>
class Solution {
public:
  int findDuplicate(std::vector<int>& nums) {
    for (int i = 0; i < nums.size(); i ++) {
      while (nums[i] - 1 != i) {
        if (nums[nums[i] - 1] == nums[i]) {
          return nums[i];
        } else {
          std::swap(nums[nums[i] - 1], nums[i]);
        }
      }
    }
    return -1;
  }
};
int main() {
  std::vector<int> nums{2,4,1,3,3,3};
  std::cout << Solution().findDuplicate(nums);
  return 0;
}
