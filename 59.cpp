#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
      vector<vector<int>> result(n, vector<int>(n));
      int x = 0, y = 0, len = n, cnt = 1;
      while (len > 0) {
        for (int i = 0; i < len; i ++) {
          result[x][y] = cnt ++;
          y ++;
        }
        y --;
        x ++;
        for (int i = 0; i < len - 1; i ++) {
          result[x][y] = cnt ++;
          x ++;
        }
        x --;
        y --;
        for (int i = 0; i < len - 1; i ++) {
          result[x][y] = cnt ++;
          y --;
        }
        y ++;
        x --;
        for (int i = 0; i < len - 2; i ++) {
          result[x][y] = cnt ++;
          x --;
        }
        x ++;
        y ++;
        len -= 2;
      }
      return result;
    }
};
int main () {
  auto res = Solution().generateMatrix(4);
  for (auto& line : res) {
    for (auto& elem : line) {
      cout << elem << ' ';
    }
    cout << endl;
  }
  return 0;
}
