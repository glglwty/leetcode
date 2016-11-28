#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;
class Solution {
public:
  void wiggleSort(vector<int>& nums) {
    auto half = (nums.size() - 1) / 2;
    nth_element(nums.begin(), nums.begin() + half, nums.end());
    int start = 1, end;
    if (nums.size() % 2 == 0) {
      end = nums.size() - 2;
    } else {
      end = nums.size() - 1;
    }
    while (start < end) {
      swap(nums[start], nums[end]);
      start += 2;
      end -= 2;
    }
  }
};
int main() {
  vector<int> nums{3, 5, 2, 1, 6, 4};
  Solution().wiggleSort(nums);
  copy(nums.begin(), nums.end(), ostream_iterator<int>(cout));
  return 0;
}
