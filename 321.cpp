#include <iostream>
#include <algorithm>
#include <vector>
class Solution {
public:
  std::vector<int> max_number_single(const std::vector<int>& nums, int k) {
    std::vector<int> q;
    int drop_count = 0;
    for (auto num : nums) {
      while (!q.empty() && q.back() < num && drop_count < nums.size() - k) {
        q.pop_back();
        drop_count ++;
      }
      q.push_back(num);
    }
    return q;
  }
  std::vector<int> maxNumber(const std::vector<int>& nums1, const std::vector<int>& nums2, int k) {
    std::vector<int> curr_best(k, 0);
    for (int i = std::max(0, int(k - nums2.size())); i <= nums1.size() && i <= k; i ++) {
      std::vector<int> curr;
      auto n1 = max_number_single(nums1, i);
      auto n2 = max_number_single(nums2, k - i);
      for (int a = 0, b = 0; curr.size() < k; ) {
        curr.push_back(std::lexicographical_compare(n1.begin() + a, n1.end(), n2.begin() + b, n2.end()) ? n2[b++] : n1[a++]);
      }
      if (std::lexicographical_compare(curr_best.begin(), curr_best.end(), curr.begin(), curr.end())) {
        curr_best = std::move(curr);
      }
    }
    return curr_best;
  }
};
int main() {
  auto calcout = [](const std::vector<int>& nums1, const std::vector<int>& nums2, int k) {
    auto res = Solution().maxNumber(nums1, nums2, k);
    std::copy(res.begin(), res.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
  };
  calcout({6, 7}, {6, 0, 4}, 5);
  calcout({3, 4, 6, 5}, {9, 1, 2, 5, 8, 3}, 5);
  calcout({6, 7}, {6, 0, 4}, 5);
  calcout({3, 9}, {8, 9}, 3);
  return 0;
}
