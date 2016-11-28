#include <iostream>
#include <string>
#include <algorithm>
class Solution {
public:
  std::string convertToTitle(int n) {
    std::string result;
    while (n != 0) {
      result.push_back((n - 1) % 26 + 'A');
      n = (n - 1) / 26;
    }
    std::reverse(result.begin(), result.end());
    return result;
  }
};
int main() {
  std::cout << Solution().convertToTitle(28) << std::endl;
  return 0;
}
