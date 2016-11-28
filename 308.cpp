#include <iostream>
#include <algorithm>
#include <vector>
class NumMatrix {
  std::vector<std::vector<int>> fenwic;
  int lowbit(int x) {
    return x & (-x);
  }
  int querySingle(int row, int col) {
    return sumRegion(row, col, row, col);
  }
  int query(int row, int col) {
      int sum = 0;
      for (int i = row + 1; i > 0; i -= lowbit(i)) {
        for (int j = col + 1; j > 0; j -= lowbit(j)) {
          sum += fenwic[i - 1][j - 1];
        }
      }
      return sum;
  }
public:
  NumMatrix(const std::vector<std::vector<int>> &matrix) {
    if (matrix.size() > 0) {
      fenwic = std::vector<std::vector<int>>(matrix.size(), std::vector<int>(matrix[0].size(), 0));
      for (int i = 0; i < matrix.size(); i ++) {
        for (int j = 0; j < matrix[0].size(); j ++) {
          update(i, j, matrix[i][j]);
        }
      }
    }
  }

  void update(int row, int col, int val) {
    int delta = val - querySingle(row, col);
    for (int i = row + 1; i <= fenwic.size(); i += lowbit(i)) {
      for (int j = col + 1; j <= fenwic[0].size(); j += lowbit(j)) {
        fenwic[i - 1][j - 1] += delta;
      }
    }

  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    return query(row2, col2) - query(row1 - 1, col2) - query(row2, col1 - 1) + query(row1 - 1, col1 - 1);
  }
};
int main() {
  // NumMatrix numMatrix({
  //   {3, 0, 1, 4, 2},
  //   {5, 6, 3, 2, 1},
  //   {1, 2, 0, 1, 5},
  //   {4, 1, 0, 1, 7},
  //   {1, 0, 3, 0, 5}
  // });
  NumMatrix numMatrix({{1, 2}});
  std::cout << numMatrix.sumRegion(0, 1, 0, 1) << std::endl;
  // numMatrix.update(3, 2, 2);
  // std::cout << numMatrix.sumRegion(2, 1, 4, 3) << std::endl;
  return 0;
}
