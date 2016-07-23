#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
class Solution {
public:
    int gcd(int a, int b) {
      if (a % b == 0) {
        return b;
      } else {
        return gcd(b, a % b);
      }
    }
    void rotate(vector<int>& nums, int k) {
      k %= nums.size();
      if (k == 0) {
        return;
      }
      int ring_num = gcd(nums.size(), k);
      for (int i = 0; i < ring_num; i ++) {
        int reserve = nums[i];
        for (int j = i, next = (i + nums.size() - k) % nums.size(); j != (i + k) % nums.size();) {
          nums[j] = nums[next];
          j = next;
          next = (j + nums.size() - k) % nums.size();
        }
        nums[(i + k) % nums.size()] = reserve;
      }
    }
};
int main() {
  vector<int> arr{1,2,3,4,5,6,7};
  Solution().rotate(arr, 3);
  copy(arr.begin(), arr.end(), ostream_iterator<int>(cout, " "));
  return 0;
}
