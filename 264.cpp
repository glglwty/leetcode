#include <iostream>
#include <algorithm>
#include <vector>
class Solution {
public:
  int nthUglyNumber(int n) {
    int t[]= {0, 0, 0}, p[] = {2, 3, 5};
    std::vector<int> ugly{1};
    while (--n) {
      int proposal[3];
      for (int i = 0; i < 3; i ++) {
        while(ugly[t[i]] * p[i] <= ugly.back()) {
          t[i] ++;
        }
        proposal[i] = ugly[t[i]] * p[i];
      }
      for (int i = 0; i < 3; i ++) {
        if (proposal[i] <= proposal[(i + 1) % 3] && proposal[i] <= proposal[(i + 2) % 3]) {
          t[i] ++;
          ugly.push_back(proposal[i]);
          break;
        }
      }
    }
    return ugly.back();
  }
};
int main() {
  for (int i = 1; i <= 10; i ++)
    std::cout << Solution().nthUglyNumber(i) << std::endl;
  return 0;
}
