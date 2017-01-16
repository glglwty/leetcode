#include <iostream>
#include <string>
class Solution {
public:
  int pow5[100] = {1, 5, 25, 125, 625, 3125, 15625, 78125};
  int counter_part[10] = {0, 1, -1, -1, -1, -1, 9, -1, 8, 6};
  int calc(const std::string& a, int start, int end, bool carry) {
    std::cout << a << ' '<<  start << ' ' << end << ' '<< carry << std::endl;
    if (start == end) {
      return !carry;
    } else if (start + 1 == end) {
      return (0 <= a[start] - '0' - carry) + (1 <= a[start] - '0' - carry) + (8 <= a[start] - '0' - carry);
    }
    int result = 0;
    for (int i = !start; i < 10; i ++) {
      if (counter_part[i] != -1) {
        if (i < a[start] - '0') {
            if ((end - start) % 2 == 0) {
              result +=  pow5[(end - start - 2) / 2];
            } else {
              result += 3 * pow5[(end - start - 3) / 2];
            }
        } else if (i == a[start] - '0') {
          result += calc(a, start + 1, end - 1, counter_part[i] > a[end - 1] - '0' - carry);
        }
      }
    }
    if (start == 0) {
      for (int i = 1; i < end; i ++) {
        if (i == 1) {
          result += 3;
        } else if (i % 2 == 0) {
          result += 4 * pow5[(i - 2) / 2];
        } else {
          result += 4 * pow5[(i - 3) / 2] * 3;
        }
      }
    }
    return result;
  }
  int strobogrammaticInRange(const std::string& low, const std::string& high) {
    return std::max(0, calc(high, 0, high.size(), false) - calc(low, 0, low.size(), true));
  }
};
int main() {
  std::cout << Solution().strobogrammaticInRange("0", "11111");
  return 0;

}
