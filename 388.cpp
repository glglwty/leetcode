#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
class Solution {
public:
  int lengthLongestPath(const std::string& input) {
    std::stack<int> s;
    int currentDepth = 0, currentStackSum = 0, result = 0;
    for (int pos = 0; pos < input.size(); pos ++) {
      int tabCount = 0;
      while (input[pos] == '\t') {
        tabCount ++;
        pos ++;
      }
      while (s.size() > tabCount) {
        currentStackSum -= s.top();
        s.pop();
      }
      bool isFile = false;
      int currentLen = 0;
      while (pos < input.size() && input[pos] != '\n') {
        if (input[pos] == '.') {
          isFile = true;
        }
        pos ++;
        currentLen ++;
      }
      if (isFile) {
        result = std::max(result, int(s.size()) + currentStackSum + currentLen);
      } else {
        currentStackSum += currentLen;
        s.push(currentLen);
      }
    }
    return result;
  }
};
int main() {
  std::cout << Solution().lengthLongestPath("dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext") << std::endl;
  return 0;
}
