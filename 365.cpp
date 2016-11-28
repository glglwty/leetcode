#include <iostream>
#include <algorithm>
class Solution {
  static int gcd(int a, int b) {
    if (a % b == 0) {
      return b;
    } else {
      return gcd(b, a % b);
    }
  }
public:
  bool canMeasureWater(int x, int y, int z) {
    if (x == 0 || y == 0) {
      return z == x || z == y;
    }
    return z % gcd(x, y) == 0;
  }
};
int main() {

}
