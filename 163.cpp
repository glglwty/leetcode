#include <iostream>
#include <algorithm>
#include <vector>
class Solution {
public:
  std::vector<std::string> findMissingRanges(const std::vector<int>& nums, int lower, int upper) {
    long long expect = lower;
    std::vector<std::string> result;
    for (auto num : nums) {
      if (num == expect) {
        expect ++;
      } else if (num > expect){
        if (num - 1 == expect) {
          result.push_back(std::to_string(expect));
        } else {
          result.push_back(std::to_string(expect) + "->" + std::to_string(num - 1));
        }
        expect = (long long)num + 1ll;
      }
    }
    if (expect == upper) {
      result.push_back(std::to_string(expect));
    } else if (expect < upper) {
      result.push_back(std::to_string(expect) + "->" + std::to_string(upper));
    }
    return result;
  }
};
int main() {
  auto result = Solution().findMissingRanges({0, 1, 3, 50, 75}, 0, 99);
  std::copy(result.begin(), result.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
  return 0;
}
