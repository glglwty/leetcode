#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
class Solution {
public:
  std::string minAbbreviation(const std::string& target, const std::vector<std::string>& dictionary) {
    std::vector<int> masks;
    for (auto& word : dictionary) {
      if (word.size() == target.size()) {
        int mask = 0;
        for (int i = 0; i < target.size(); i ++) {
          if (target[i] != word[i]) {
            mask |= (1 << i);
          }
        }
        masks.push_back(mask);
      }
    }
    std::string solution = target;
    int solution_length = target.size();
    for (int i = 0; i < (1 << target.size()); i ++) {
      int len = 0;
      for (int j = 0; j < target.size(); j ++) {
        if (j == 0 || ((i >> (j - 1)) & 3)) {
          len += 1;
        }
      }
      if (len < solution_length &&
        std::all_of(masks.begin(), masks.end(), [i](int mask) {
        return mask & i;
      })) {
        solution_length = len;
        solution.clear();
        int num = 0;
        for (int j = 0; j < target.size(); j ++) {
          if ((i >> j) & 1) {
            if (num != 0) {
              solution += std::to_string(num);
              num = 0;
            }
            solution.push_back(target[j]);
          } else {
            num ++;
          }
        }
        if (num != 0) {
          solution += std::to_string(num);
        }
      }
    }
    return solution;
  }
};
int main() {
  std::cout << Solution().minAbbreviation("apple", {"plain", "amber", "blade"})
    << std::endl;
  return 0;
}
