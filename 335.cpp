#include <iostream>
#include <algorithm>
#include <vector>
class Solution {
public:
  bool isSelfCrossing(const std::vector<int>& x) {
    for (int i = 0; i < x.size(); i ++) {
      if (i >= 3 && x[i] >= x[i - 2] && x[i - 1] <= x[i - 3]) {
        return true;
      }
      if (i >= 4 && x[i - 1] == x[i - 3] && x[i] + x[i - 4] >= x[i - 2]) {
        return true;
      }
      if (i >= 5 && x[i - 2] >= x[i - 4] && x[i - 3] >= x[i - 1] && x[i] + x[i - 4] >= x[i - 2] && x[i - 1] + x[i - 5] >= x[i - 3]) {

        return true;
      }
    }
    return false;
  }
};
int main() {
  std::cout << Solution().isSelfCrossing({1,1,2,2,3,3,4,4,10,4,4,3,3,2,2,1,1});
   return 0;
}
