#include <iostream>
#include <deque>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int, int>> q;
        vector<int> result;
        for (int i = 0; i < nums.size(); i ++) {
          while (!q.empty() && i - q.front().first >= k) {
            q.pop_front();
          }
          while (!q.empty() && q.back().second <= nums[i]) {
            q.pop_back();
          }
          q.emplace_back(i, nums[i]);
          if (i >= k - 1) {
            result.push_back(q.front().second);
          }
        }
        return result;
    }
};
int main() {
  vector<int> nums{1,3,-1,-3,5,3,6,7};
  auto result = Solution().maxSlidingWindow(nums, 3);
  copy(result.begin(), result.end(), ostream_iterator<int>(cout));
  return 0;
}
