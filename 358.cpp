#include <iostream>
#include <algorithm>
#include <vector>
class Solution {
public:
  std::string rearrangeString(const std::string& str, int k) {
    int latestPos[26];
    int remainingCount[26];
    std::fill(std::begin(latestPos), std::end(latestPos), -k);
    std::fill(std::begin(remainingCount), std::end(remainingCount), 0);
    for (auto c : str) {
      remainingCount[c - 'a'] ++;
    }
    std::string result;
    for (int i = 0; i < str.size(); i ++) {
      std::pair<int, char> currentMax{-1, '\0'};
      for (char c = 'a'; c <= 'z'; c ++) {
        if (remainingCount[c - 'a'] > 0 && i - latestPos[c - 'a'] >= k) {
          currentMax = std::max(currentMax, {remainingCount[c - 'a'], c});
        }
      }
      if (currentMax.first == -1) {
        return "";
      } else {
        result.push_back(currentMax.second);
        remainingCount[currentMax.second - 'a'] --;
        latestPos[currentMax.second - 'a'] = i;
      }
    }
    return result;
  }
};
int main () {
  std::cout << Solution().rearrangeString("aaadbbcc", 2) << std::endl;
  std::cout << Solution().rearrangeString("aaabc", 3) << std::endl;
  std::cout << Solution().rearrangeString("aabbcc", 3) << std::endl;
  return 0;
}
