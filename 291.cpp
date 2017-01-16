#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <unordered_set>
using std::vector;
using std::string;
class Solution {
  std::pair<int, int> match[26]; //start, size
  std::unordered_set<string> reverse_set;
  bool dfs(const string& pattern, const string& str, int ppos, int spos) {
    if (ppos == pattern.size() || spos == str.size()) {
      return ppos == pattern.size() && spos == str.size();
    }
    auto& cur_match = match[pattern[ppos] - 'a'];
    if (cur_match.first != -1) {
      if (cur_match.second + spos > str.size()) {
        return false;
      }
      for (int i = 0; i < cur_match.second; i ++) {
        if (str[cur_match.first + i] != str[spos + i]) {
          return false;
        }
      }
      return dfs(pattern, str, ppos + 1, spos + cur_match.second);
    } else {
      for (int i = 1; i + spos <= str.size(); i ++) {
        if (reverse_set.find(str.substr(spos, i)) != reverse_set.end()) {
          continue;
        }
        reverse_set.insert(str.substr(spos, i));
        cur_match = {spos, i};
        if (dfs(pattern, str, ppos + 1, spos + i)) {
          return true;
        }
        cur_match = {-1, -1};
        reverse_set.erase(str.substr(spos, i));
      }
    }
    return false;
  }
public:
  bool wordPatternMatch(const string& pattern, const string& str) {
    std::fill(std::begin(match), std::end(match), std::make_pair(-1, -1));
    return dfs(pattern, str, 0, 0);
  }
};
int main() {
  std::cout << Solution().wordPatternMatch("aaaa", "asdasdasdasd") << std::endl;
  return 0;
}
