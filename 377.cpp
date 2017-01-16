#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <unordered_set>
using std::vector;
using std::string;
class Solution {
public:
  int combinationSum4(const vector<int>& nums, int target) {
    vector<int> f(target + 1, 0);
    f[0] = 1;
    for (int i = 1; i <= target; i ++) {
      for (auto& num : nums) {
        if (num <= i) {
          f[i] += f[i - num];
        }
      }
    }
    return f.back();
  }
};
int main() {
  std::cout << Solution().combinationSum4({3, 33, 333}, 10000);
  return 0;
}
