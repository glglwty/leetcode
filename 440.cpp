#include <iostream>
class Solution {
public:
  int findKthNumber(long long n, long long k) {
    long long a = 1;
    while (k > 1) {
      long long b = a, c = a + 1, size = 0;
      while (b <= n) {
        size += std::min(c, n + 1) - b;
        b *= 10;
        c *= 10;
      }
      if (k <= size) {
        k --;
        a *= 10;
      } else {
        k -= size;
        a ++;
      }
    }
    return a;
  }
};
int main() {
  std::cout << Solution().findKthNumber(100, 10);
  return 0;
}
