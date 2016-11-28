#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(const vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return {};
        }
        int uppermost = 0, leftmost = 0, bottommost = matrix.size(), rightmost = matrix[0].size();
        int deltax = 0, deltay = 1, x = 0, y = 0;
        vector<int> result {matrix[0][0]};
        bool turning = false;
        while (true) {
          int nextx = x + deltax, nexty = y + deltay;
          if (! (nextx >= uppermost && nextx < bottommost && nexty >= leftmost && nexty < rightmost)) {
            if (turning) {
              break;
            } else {
              if (deltax == 0 && deltay == 1) {
                uppermost ++;
              } else if (deltax == 0 && deltay == -1) {
                bottommost --;
              } else if (deltax == 1 && deltay == 0) {
                rightmost --;
              } else {
                leftmost ++;
              }
              deltax += deltay;
              deltay = - (deltax - deltay);
              deltax += deltay;
              turning = true;
              continue;
            }
          }
          turning = false;
          result.push_back(matrix[nextx][nexty]);
          x = nextx;
          y = nexty;
        }
        return result;
    }
};
int main() {
  auto sol = Solution().spiralOrder({{1},{2},{3}});
  copy(sol.begin(), sol.end(), ostream_iterator<int>(cout));
  return 0;
}
