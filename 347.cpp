#include <unordered_map>
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
class Solution {
public:
  std::vector<int> topKFrequent(const std::vector<int>& nums, int k) {
    std::unordered_map<int, int> frequency_map;
    for (auto num : nums) {
      auto it = frequency_map.find(num);
      if (it == frequency_map.end()) {
        frequency_map.insert(it, std::make_pair(num, 0));
      } else {
        it->second ++;
      }
    }
    std::vector<std::vector<int>> buckle(nums.size(), std::vector<int>());
    for (auto pr : frequency_map) {
      buckle[pr.second].push_back(pr.first);
    }
    std::vector<int> result;
    for (int i = nums.size() - 1; i >= 0 && k > 0; i --) {
      for (auto num : buckle[i]) {
        result.push_back(num);
        k -= 1;
      }
    }
    return result;
  }
};
int main() {
  auto result = Solution().topKFrequent({1, 1, 1, 2, 2, 3}, 2);
  std::copy(result.begin(), result.end(), std::ostream_iterator<int>(std::cout, " "));
  return 0;
}
