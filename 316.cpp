#include <iostream>
#include <algorithm>
#include <deque>
class Solution {
public:
  std::string removeDuplicateLetters(const std::string& str) {
    int frequency[256];
    bool inqueue[256], visited[256];
    std::fill(std::begin(frequency), std::end(frequency), 0);
    std::fill(std::begin(inqueue), std::end(inqueue), false);
    std::fill(std::begin(visited), std::end(visited), false);
    for (auto c : str) {
      frequency[c] ++;
    }
    std::deque<std::pair<char, int>> s;
    std::string result;
    for (int i = 0; i < str.size(); i ++) {
      if (visited[str[i]]) {
        continue;
      }
      if (!inqueue[str[i]]) {
        std::pair<char, int> cur(str[i], i);
        while (!s.empty() && s.back() > cur) {
          inqueue[s.back().first] = false;
          s.pop_back();
        }
        s.push_back(cur);
        inqueue[str[i]] = true;
      }
      //cannot remove this char
      while (!s.empty() && frequency[str[i]] <= 1) {
        //try reserve the best candidiate
        auto r = s.front();
        s.pop_front();
        result.push_back(r.first);
        frequency[r.first] ++;
        visited[r.first] = true;
      }
      if (!s.empty()) {
        frequency[str[i]] --;
      }
    }
    return result;
  }
};

int main() {
  std::cout << Solution().removeDuplicateLetters("bcabc") << std::endl;
  return 0;
}
