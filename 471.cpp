#include <iostream>
#include <vector>
class Solution {
public:
  std::string encode(const std::string& s) {
    std::vector<std::vector<std::string>> dp(s.size(), std::vector<std::string>(s.size()));
    for (int i = 0; i < s.size(); i ++) {
      for (int j = 0; i + j < s.size(); j ++) {
        auto substr = s.substr(j, i + 1);
        dp[i][j] = substr;
        if (i != 0) {
          std::pair<int, int> bestlen = {i + 1, -1};
          for (int k = j; k < i + j; k ++) {
            bestlen = std::min(bestlen, {dp[k - j][j].length() + dp[i - k + j - 1][k + 1].length() , k});
          }
          if (bestlen.second != -1) {
            dp[i][j] = dp[bestlen.second - j][j] + dp[i - bestlen.second + j - 1][bestlen.second + 1];
          }
        }
        auto pos = (substr + substr).find(substr, 1);
        if (pos != std::string::npos) {
          auto num_str = std::to_string((i + 1) / pos);
          if (num_str.length() + 2 + dp[pos - 1][j].length() < dp[i][j].length()) {
            dp[i][j] = num_str + "[" + dp[pos - 1][j] + "]";
          }
        }
      }
    }
    return dp[s.size() - 1][0];
  }
};
int main() {
  std::cout << Solution().encode("aaa") << std::endl;
  std::cout << Solution().encode("aaaaa") << std::endl;
  std::cout << Solution().encode("aaaaaaaaaa") << std::endl;
  std::cout << Solution().encode("abbbabbbcabbbabbbc") << std::endl;
  return 0;
}
