#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;
class Solution {
public:
  void wiggleSort(vector<int>& nums) {
    std::nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
    copy(nums.begin(), nums.end(), ostream_iterator<int>(cout));
    cout << endl;
    int medium = nums[nums.size() / 2];

    auto remapped = [&](int idx) -> int& {
      if (idx <= nums.size() / 2 - 1 + nums.size() % 2) {
        return nums[nums.size() - idx * 2 - 2 + nums.size() % 2];
      } else {
        return nums[(nums.size() - idx) * 2 - 1];
      }
    };
    cout << medium << endl;
    int i = 0, j = 0, k = nums.size() - 1;
    while (i <= k) {
      if (remapped(i) > medium) {
        cout << "back" << k << ' ' << remapped(i) << endl;
        std::swap(remapped(i), remapped(k --));
      } else if (remapped(i) < medium) {
        cout << "front" << j << ' ' << remapped(i) << endl;
        std::swap(remapped(i ++), remapped(j ++));
      } else {
        i ++;
      }
    }
  }
};
int main() {
  vector<int> nums{4, 5, 5, 6};
  Solution().wiggleSort(nums);
  copy(nums.begin(), nums.end(), ostream_iterator<int>(cout));
  return 0;
}
