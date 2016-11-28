#include <iostream>
#include <vector>
#include <string>
class Solution {
public:
  int lengthOfLongestSubstringTwoDistinct(const std::string& s) {
    int frequency[256];
    std::fill(std::begin(frequency), std::end(frequency), 0);
    int cur_distinct_num = 0;
    int solution = 0;
    for (int i = 0, j = 0; j < s.size(); j ++) {
      if (frequency[s[j]] ++ == 0) {
        if (cur_distinct_num < 2) {
          cur_distinct_num ++;
        } else {
          while (frequency[s[i++]] -- != 1);
        }
      }
      if (j - i + 1 > solution) {
        solution = j - i + 1;
      }
    }
    return solution;
  }
};
int main() {
  std::cout << Solution().lengthOfLongestSubstringTwoDistinct("cdaba") << std::endl;
  return 0;
}
