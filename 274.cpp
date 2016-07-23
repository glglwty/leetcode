#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
      int result = 0;
      for (int i = 0; i < 31; i ++) {
        if ((m & (1 << i)) == 0 || (n & (1 << i)) == 0) {
          continue;
        }
        if (n - m < (1 << i)) {
          result |= (1 << i);
        }
      }
      return result;
    }
};
int main() {
  cout << Solution().rangeBitwiseAnd(5, 7);
  return 0;
}
