#include <iostream>
#include <algorithm>
class Solution {
public:
  int maximumGap(vector<int>& nums) {
      std::vector<int> bucket[10];
      for (int a = 1000000000; a >= 1; a /= 10) {
        for (auto num : nums) {
          bucket[num / a % 10].push_back(num);
        }
        nums.clear();
        for (auto& b : bucket) {
          nums.insert(nums.begin(), b.begin(), b.end());
          b.clear();
        }
      }
      int result = 0;
      for (int i = 0; i < nums.size() - 1; i ++) {
        result = std::max(result, nums[i + 1] - nums[i]);
      }
      return result;
  }
};
int main() {
  std::vector<int> a {}
}
