#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <unordered_set>
using std::vector;
using std::string;
using std::unordered_set;
class Solution {
  unordered_set<string> r;
  void dfs(const string& s, int n, string& cur, int k) {
    if (n == s.size()) {
      if (k == 0) {
        if (r.empty() || cur.size() == r.begin()->size()) {
          r.insert(cur);
        } else if (cur.size() > r.begin()->size()) {
          r.clear();
          r.insert(cur);
        }
      }
      return;
    }
    if (s[n] == '(' || s[n] == ')') {
      dfs(s, n + 1, cur, k);
    }
    if (s[n] != ')' || k != 0) {
      cur.push_back(s[n]);
      dfs(s, n + 1, cur, k + (s[n] == '(') - (s[n] == ')'));
      cur.pop_back();
    }
  }
public:
  vector<string> removeInvalidParentheses(const string& s) {
    string cur;
    dfs(s, 0, cur, 0);
    vector<string> out(r.begin(), r.end());
    return out;
  }
};
int main() {
   auto r = Solution().removeInvalidParentheses("(a)())()");
   std::copy(r.begin(), r.end(), std::ostream_iterator<string>(std::cout, "\n"));
   return 0;
}
