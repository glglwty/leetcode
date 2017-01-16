#include <iostream>
#include <vector>
#include <unordered_map>
class Solution {
public:
  int numberOfArithmeticSlices(const std::vector<int>& A) {
    std::vector<std::unordered_map<long long, int>> hashmaps;  //[step -> numberOfArithmeticSlices]
    hashmaps.emplace_back();
    for (int i = 1; i < A.size(); i ++) {
      hashmaps.emplace_back();
      for (int j = 0; j < i; j ++) {
        auto step = static_cast<long long>(A[i]) - A[j];
        hashmaps[i][step] ++;
        auto it = hashmaps[j].find(step);
        if (it != hashmaps[j].end()) {
          hashmaps[i][step] += it->second;
        }
      }
    }
    int result = - A.size() * (A.size() - 1) / 2;
    for (auto& map : hashmaps) {
      for (auto& pi : map) {
        result += pi.second;
      }
    }
    return result;
  }
};
int main() {
  std::cout << Solution().numberOfArithmeticSlices({2, 4, 6, 8, 10});
  return 0;
}
