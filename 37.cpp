#include <iostream>
#include <algorithm>
#include <vector>
using std::vector;
class Solution {
public:
  int cell_id(int x, int y) {
    return (x / 3) * 3 + y / 3;
  }
  bool dfs(int x, int y, vector<vector<char>>& board, bool row[9][9], bool col[9][9], bool cel[9][9]) {
    if (x == 9) {
      return true;
    }
    int next_x = x, next_y = y + 1;
    if (y == 9) {
      next_y = 0;
      next_x = x + 1;
    }
    if (board[x][y] != '.') {
      return dfs(next_x, next_y, board, row, col, cel);
    }
    for (int i = 1; i <= 9; i ++) {
      if (!row[x][i - 1] && !col[y][i - 1] && !cel[cell_id(x, y)][i - 1]) {
        row[x][i - 1] = col[y][i - 1] = cel[cell_id(x, y)][i - 1] = true;
        board[x][y] = i + '0';
        if (dfs(next_x, next_y, board, row, col, cel)) {
          return true;
        }
        row[x][i - 1] = col[y][i - 1] = cel[cell_id(x, y)][i - 1] = false;
      }
    }
    board[x][y] = '.';
    return false;
  }

  void solveSudoku(vector<vector<char>>& board) {
    bool row[9][9] {}, col[9][9] {}, cel[9][9] {};
    auto b = [&board](int x, int y) {
      return board[x][y] == '.' ? 0 : board[x][y] - '0';
    };
    for (int i = 0; i < 9; i ++) {
      for (int j = 0; j < 9; j ++) {
        if (b(i, j)) {
          row[i][b(i, j) - 1] = col[j][b(i, j) - 1] = cel[cell_id(i, j)][b(i, j) - 1] = true;
        }
      }
    }
    dfs(0, 0, board, row, col, cel);
  }
};
int main() {
  vector<vector<char>> b {
    {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
    {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
    {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
    {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
    {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
    {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
    {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
    {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
    {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
  };

  for (auto& line : b) {
    std::copy(line.begin(), line.end(), std::ostream_iterator<char>(std::cout, ""));
    std::cout << std::endl;
  }
  Solution().solveSudoku(b);
  for (auto& line : b) {
    std::copy(line.begin(), line.end(), std::ostream_iterator<char>(std::cout, ""));
    std::cout << std::endl;
  }
  return 0;
}
