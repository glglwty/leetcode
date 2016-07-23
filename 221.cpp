#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int maximalSquare(const vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
          return 0;
        }
        vector<int> col_num_1s(matrix[0].size(), 0);
        vector<int> square_size(matrix[0].size(), 0);
        vector<int> square_size_new(matrix[0].size(), 0);
        int max_size = 0;
        for (auto& line : matrix) {
          int row_num_1s = 0;
          for (int i = 0; i < line.size(); i ++) {
            if (line[i] == '1') {
              row_num_1s ++;
              col_num_1s[i] ++;
              if (i == 0) {
                square_size_new[0] = 1;
              } else {
                square_size_new[i] = min(square_size[i - 1] + 1, min(row_num_1s, col_num_1s[i]));
              }
            } else {
              col_num_1s[i] = 0;
              row_num_1s = 0;
              square_size_new[i] = 0;
            }
            max_size = max(max_size, square_size_new[i]);
          }
          square_size.swap(square_size_new);
        }
        return max_size * max_size;
    }
    int maximalSquare2(const vector<string>& matrix) {
      vector<vector<char>> aux;
      for (auto& line : matrix) {
        aux.emplace_back(line.begin(), line.end());
      }
      return maximalSquare(aux);
    }
};
int main() {
  cout << Solution().maximalSquare2(
    {
      "10100",
      "10111",
      "11111",
      "10010"
    }
  );
  return 0;
}
