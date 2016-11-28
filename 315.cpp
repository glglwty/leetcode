#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
//mergesort / fucking trees
class Solution {
  std::vector<std::pair<int, int>> seq, workspace;
  std::vector<int> result;
  void mergesort(int begin, int end) {
    if (begin + 1 == end) {
      return;
    }
    int half = (begin + end) / 2;
    mergesort(begin, half);
    mergesort(half, end);
    std::copy(seq.begin() + begin, seq.begin() + end, workspace.begin());
    for (int i = 0, j = half - begin, o = begin; i < half - begin || j < end - begin; ) {
      if (j == end - begin || (i != half - begin && workspace[i].first <= workspace[j].first)) {
        result[workspace[i].second] += j - (half - begin);
        seq[o++] = workspace[i ++];
      } else {
        seq[o++] = workspace[j ++];
      }
    }
  }
public:
  std::vector<int> countSmaller(const std::vector<int>& nums) {
    if (nums.empty()) {
      return {};
    }
    for (int i = 0; i < nums.size(); i ++) {
      seq.emplace_back(nums[i], i);
    }
    workspace.resize(nums.size());
    result.resize(nums.size(), 0);
    mergesort(0, nums.size());
    return std::move(result);
  }
};
int main() {
  auto result = Solution().countSmaller({5, 2, 6, 1});
  std::copy(result.begin(), result.end(), std::ostream_iterator<int>(std::cout, " "));
  return 0;
}
