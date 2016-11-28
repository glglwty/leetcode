#include <iostream>
#include <vector>
#include <algorithm>
class Solution {
public:
  bool isMatch(const std::string& s, const std::string& p) {
    std::vector<std::vector<bool>> f(s.size() + 1, std::vector<bool>(p.size() + 1, false));
    f[0][0] = true;
    for (int j = 1; j <= p.size(); j ++) {
      if (p[j - 1] == '*') {
        f[0][j] = true;
      } else if (j != 1 && p[j - 2] != '*') {
        break;
      }
    }

    for (int i = 1; i <= s.size(); i ++) {
      for (int j = 1; j <= p.size(); j ++) {
        if (p[j - 1] == '*') {
          f[i][j] = f[i][j - 2] || (f[i - 1][j] && (p[j - 2] == '.' || s[i - 1] == p[j - 2]));
        } else if (p[j - 1] == '.') {
          f[i][j] = f[i - 1][j - 1];
        } else {
          f[i][j] = f[i - 1][j - 1] && s[i - 1] == p[j - 1];
        }
        std::cout << i << ' ' << j << ' ' << f[i][j] << std::endl;
      }
    }
    return f[s.size()][p.size()];
  }
};
int main() {
  std::cout << Solution().isMatch("aa","a") << std::endl;
  std::cout << Solution().isMatch("aa","aa") << std::endl;
  std::cout << Solution().isMatch("aaa","aa") << std::endl;
  std::cout << Solution().isMatch("aa", "a*") << std::endl;
  std::cout << Solution().isMatch("aa", ".*") << std::endl;
  std::cout << Solution().isMatch("ab", ".*") << std::endl;
  std::cout << Solution().isMatch("aab", "c*a*b") << std::endl;
  return 0;
}
