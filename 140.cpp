#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <iterator>
#include <functional>
class Solution {
public:
  std::vector<std::string> wordBreak(const std::string& s, const std::unordered_set<std::string>& wordDict) {
    std::vector<std::vector<std::unordered_set<std::string>::const_iterator>> f;
    for (int i = 0; i < s.size(); i ++) {
      f.emplace_back();
      for (int j = -1; j < i; j ++) {
        if (j == -1 || !f[j].empty()) {
          auto it = wordDict.find(s.substr(j + 1, i - j));
          if (it != wordDict.end()) {
            f[i].push_back(it);
          }
        }
      }
    }
    std::vector<std::string> result;
    std::vector<std::unordered_set<std::string>::const_iterator> curr;
    std::function<void(int)> g = [&](int n) {
      if (n == -1) {
        std::string str;
        for (int i = curr.size() - 1; i >= 0; i --) {
          str += *curr[i];
          if (i != 0) {
            str += " ";
          }
        }
        result.emplace_back(std::move(str));
      } else {
        for (auto it : f[n]) {
          curr.push_back(it);
          g(n - it->size());
          curr.pop_back();
        }
      }
    };
    g(s.size() - 1);
    return result;
  }
};
int main() {
  auto r = Solution().wordBreak("catsanddog", {"cat", "cats", "and", "sand", "dog"});
  std::copy(r.begin(), r.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
  return 0;
}
