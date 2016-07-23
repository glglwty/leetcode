#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<pair<int, int>>> A_row_repr;
        vector<vector<pair<int, int>>> B_col_repr(B[0].size());
        for (auto& row : A) {
          A_row_repr.push_back({});
          for (int col = 0; col < row.size(); col ++) {
            if (row[col] != 0) {
              A_row_repr.back().emplace_back(col, row[col]);
            }
          }
        }
        for (int i = 0; i < B.size(); i ++) {
          for (int j = 0; j < B[0].size(); j ++) {
            if (B[i][j] != 0) {
              B_col_repr[j].emplace_back(i, B[i][j]);
            }
          }
        }
        vector<vector<int>> result(A.size(), vector<int>(B[0].size(), 0));
        for (int i = 0; i < A.size(); i ++) {
          for (int j = 0; j < B[0].size(); j ++) {
            auto& A_row = A_row_repr[i];
            auto& B_col = B_col_repr[j];
            auto A_iter = A_row.begin();
            auto B_iter = B_col.begin();
            while(A_iter != A_row.end() && B_iter != B_col.end()) {
              if (A_iter->first == B_iter->first) {
                result[i][j] += A_iter->second * B_iter->second;
                A_iter ++;
                B_iter ++;
              } else if (A_iter->first < B_iter->first) {
                A_iter ++;
              } else {
                B_iter ++;
              }
            }
          }
        }
        return result;
    }
};
int main() {
  vector<vector<int>> A{{1, 0, 0}, {-1, 0, 3}};
  vector<vector<int>> B{{7, 0, 0}, {0, 0, 0}, {0, 0, 1}};
  auto result = Solution().multiply(A, B);
  for (auto& row : result) {
    for (int col : row) {
      cout << col << ' ';
    }
    cout << endl;
  }
  return 0;
}
