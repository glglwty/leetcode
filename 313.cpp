#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;
class Solution {
public:
    int nthSuperUglyNumber(int n, const vector<int>& primes) {
      vector<int> ugly;
      ugly.push_back(1);
      priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;
      for (int i = 0; i < primes.size(); i ++) {
        q.emplace(primes[i], 0, i);
      }
      for (;ugly.size() < n;) {
        if (ugly.back() != get<0>(q.top())) {
          ugly.push_back(get<0>(q.top()));
        }
        auto t = q.top();
        q.pop();
        q.emplace(ugly[get<1>(t) + 1] * primes[get<2>(t)], get<1>(t) + 1, get<2>(t));
      }
      return ugly.back();
    }

};
int main() {
  cout << Solution().nthSuperUglyNumber(12, {2, 7, 13, 19});
  return 0;
}
