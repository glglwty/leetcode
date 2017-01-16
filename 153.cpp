#include <iostream>
#include <vector>
using std::vector;
class Solution {
public:
  int findMin(const vector<int>& nums) {
    if (nums[0] <= nums.back()) {
      return nums[0];
    }
    int l = 1, r = nums.size();
    while (l + 1 < r) {
      int m = (l + r - 1) / 2;
      if (nums[m] > nums[0]) {
        l = m + 1;
      } else {
        r = m + 1;
      }
    }
    return nums[l];
  }
};
int main() {
  std::cout << Solution().findMin({4, 5, 6, 7, 0, 1, 2});
  return 0;
}
