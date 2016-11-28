#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
class Solution {
public:
  int maxEnvelopes(std::vector<std::pair<int, int>>& envelopes) {
    if (envelopes.empty()) {
      return 0;
    }
    std::sort(std::begin(envelopes), std::end(envelopes), [](const std::pair<int, int>& a, const std::pair<int, int> &b) {
      return a.first < b.first || (a.first == b.first && a.second > b.second);
    });
    envelopes.erase(std::unique(envelopes.begin(), envelopes.end()), envelopes.end());
    std::vector<int> f{0};
    for (auto env : envelopes) {
      auto it = std::lower_bound(f.begin(), f.end(), env.second);
      if (it == f.end()) {
        f.push_back(env.second);
      } else {
        *it = env.second;
      }
    }
    return f.size() - 1;
  }
};
int main() {
  std::vector<std::pair<int, int>> d{{30, 50}, {12, 2}, {12, 15}, {2, 3}};
  std::cout << Solution().maxEnvelopes(d) << std::endl;
  return 0;
}
