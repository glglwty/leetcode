#include <iostream>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        if (x == 0) {
            return true;
        }
        int y = 1;
        while (y <= numeric_limits<int>::max() / 10 && y * 10 <= x) {
            y = y * 10;
        }
        while (x != 0) {
          cout << x << ' ' << y << endl;
            if (x / y != x % 10) {
                return false;
            }
            x = (x % y) / 10;
            y /= 100;
        }
        return true;
    }
};
int main() {
  cout << Solution().isPalindrome(1410110141);
  return 0;
}
