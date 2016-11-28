#include <iostream>
#include <vector>
#include <cstdlib>
class Solution {
public:
  std::vector<long long> workspace, prefixes;
  int result = 0, lower, upper;
  void merge_sort(int begin, int end) {
    if (end - begin == 1) {
      return;
    }
    int half = (end + begin) / 2;
    merge_sort(begin, half);
    merge_sort(half, end);
    for (int i = begin, j = half, k = half; i < half; i ++) {
      while (j < end && prefixes[j] < prefixes[i] + lower) {
        j ++;
      }
      while (k < end && prefixes[k] < prefixes[i] + upper + 1) {
        k ++;
      }
      result += k - j;
    }
    std::copy(prefixes.begin() + begin, prefixes.begin() + end, workspace.begin());
    for (int i = 0, j = half - begin, o = begin; i < half - begin || j < end - begin; ) {
      if (j == end - begin || (i < half - begin && workspace[i] < workspace[j])) {
        prefixes[o ++] = workspace[i ++];
      } else {
        prefixes[o ++] = workspace[j ++];
      }
    }
  }
  int countRangeSum(const std::vector<int>& nums, int lower_, int upper_) {
    lower = lower_;
    upper = upper_;
    long long prefix_sum = 0;
    prefixes.push_back(0);
    for (auto num : nums) {
      prefix_sum += num;
      prefixes.push_back(prefix_sum);
    }
    workspace.resize(prefixes.size());
    merge_sort(0, prefixes.size());
    return result;
  }
};
int main() {
  std::cout << Solution().countRangeSum({-2, 5, -1}, -2, 2) << std::endl;
  return 0;
}
