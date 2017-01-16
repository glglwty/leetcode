#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <unordered_set>
using std::vector;
using std::string;
class Solution {
public:
  int getMoneyAmount(int n) {
    vector<vector<int>> f(n, vector<int>(n, 0));
    for (int i = 1; i <= n; i ++) {
      f[i - 1][i - 1] = 0;
      if (i != n) {
        f[i - 1][i] = i;
      }
    }
    for (int i = 3; i <= n; i ++) {
      for (int j = 1; j + i - 1 <= n; j ++)  {
        f[j - 1][j + i - 2] = std::numeric_limits<int>::max();
        for (int k = j + 1; k < j + i - 1; k ++) {
          f[j - 1][j + i - 2] = std::min(f[j - 1][j + i - 2],
            k + std::max(f[j - 1][k - 2], f[k][i + j - 2])
          );
        }
      }
    }
    return f[0][n - 1];
  }
};
int main() {
  std::cout << Solution().getMoneyAmount(1);
}
