#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
class Solution {
public:
  int lengthOfLongestSubstringKDistinct(const std::string& s, int k) {
    int r = 0;
    int frequency[256];
    std::fill(std::begin(frequency), std::end(frequency), 0);
    for (int i = 0, j = 0, distinct_count = 0; i < s.size(); i ++) {
      if (frequency[s[i]] == 0) {
        distinct_count ++;
      }
      frequency[s[i]] ++;
      for (; j <= i && distinct_count > k; j ++) {
        frequency[s[j]] --;
        if (frequency[s[j]] == 0) {
          distinct_count --;
        }
      }
      r = std::max(r, i - j + 1);
    }
    return r;
  }
};
int main() {
  std::cout << Solution().lengthOfLongestSubstringKDistinct("eceba", 2) << std::endl;
  return 0;
}
