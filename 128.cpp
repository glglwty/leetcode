#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
class Solution {
public:
  int longestConsecutive(const std::vector<int>& nums) {
    int result = 0;
    std::unordered_set<int> s(nums.begin(), nums.end());
    while (!s.empty()) {
      auto k = *s.begin();
      s.erase(s.begin());
      int cur_length = 1;
      for (int delta : {-1, 1}) {
        for (int i = k + delta; ; i += delta) {
          auto it = s.find(i);
          if (it != s.end()) {
            cur_length ++;
            s.erase(it);
          } else {
            break;
          }
        }
      }
      result = std::max(result, cur_length);
    }
    return result;
  }
};
int main() {
  std::cout << Solution().longestConsecutive({100, 4, 200, 1, 3, 2}) << std::endl;
  return 0;
}
