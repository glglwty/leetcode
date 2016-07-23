#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    void search(
      int n,
      vector<int>& solu,
      vector<bool>& col_occupy,
      vector<bool>& main_diag_occupy,
      vector<bool>& counter_diag_occupy,
      vector<vector<string>>& result
    ) {
      if (solu.size() == n) {
        result.push_back(vector<string>());
        auto& r = result.back();
        for (int i = 0; i < n; i ++) {
          r.push_back("");
          for (int j = 0; j < n; j ++) {
              r.back().push_back(solu[i] == j ? 'Q' : '.');
          }
        }
      } else {
        for (int i = 0; i < n; i ++) {
          int col_id = i,
            main_diag_id = i - solu.size() + n - 1,
            counter_diag_id = solu.size() + i;
          if (!(col_occupy[col_id] ||
            main_diag_occupy[main_diag_id] ||
            counter_diag_occupy[counter_diag_id])) {
            solu.push_back(i);
            col_occupy[col_id] = true;
            main_diag_occupy[main_diag_id] = true;
            counter_diag_occupy[counter_diag_id] = true;
            search(n, solu, col_occupy, main_diag_occupy, counter_diag_occupy,
              result);
            col_occupy[col_id] = false;
            main_diag_occupy[main_diag_id] = false;
            counter_diag_occupy[counter_diag_id] = false;
            solu.pop_back();
          }
        }
      }
    }
    vector<vector<string>> solveNQueens(int n) {
      vector<int> solu;
      vector<bool> col_occupy(n, false);
      vector<bool> main_diag_occupy(n + n - 1, false);
      vector<bool> counter_diag_occupy(n + n - 1, false);
      vector<vector<string>> result;
      search(n, solu, col_occupy, main_diag_occupy, counter_diag_occupy, result);
      return result;
    }
};
int main() {
  auto solus = Solution().solveNQueens(12);
  for (auto& solu : solus) {
    for (auto& line : solu) {
      cout << line << endl;
    }
    cout << endl;
  }
  return 0;
}
