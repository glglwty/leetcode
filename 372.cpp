#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int superPow(int a, vector<int>& b) {
      a = a % 1337;
      int current_base = a, result = 1;
      for (int i = b.size() - 1; i >= 0; i --) {
        for (int j = 0; j < b[i]; j ++) {
          result = result * current_base % 1337;
        }
        int next_base = 1;
        for (int j = 0; j < 10; j ++) {
          next_base = next_base * current_base % 1337;
        }
        current_base = next_base;
      }
      return result;
    }
};
int main() {
  vector<int> b{1, 0};
  cout << Solution().superPow(2, b);
  return 0;
}
