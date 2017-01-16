#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
class Solution {
public:
  int minTransfers(const std::vector<std::vector<int>>& transactions) {
    std::unordered_map<int, int> balance;
    auto add_balance = [&balance](int person, int delta) {
      auto it = balance.find(person);
      if (it == balance.end()) {
        balance.insert(it, {person, delta});
      } else {
        it->second += delta;
      }
    };
    for (auto& tran : transactions) {
      add_balance(tran[0], tran[2]);
      add_balance(tran[1], -tran[2]);
    }
    std::vector<int> nz_balance;
    for (auto& pi : balance) {
      if (pi.second != 0) {
        nz_balance.push_back(pi.second);
      }
    }
    if (nz_balance.size() == 0) {
      return 0;
    }
    std::vector<int> subset(1 << nz_balance.size(), -1);
    for (int i = 1; i < subset.size(); i ++) {
      int sum = 0, count = 0;
      for (int j = 0; j < nz_balance.size(); j ++) {
        if ((i >> j) & 1) {
          sum += nz_balance[j];
          count ++;
        }
      }
      if (sum == 0) {
        subset[i] = count - 1;
        for (int j = 1; j < i; j ++) {
          if ((i & j) == j && subset[j] >= 0 && subset[i - j] >= 0) {
            subset[i] = std::min(subset[i], subset[j] + subset[i - j]);
          }
        }
      }
    }
    return subset.back();
  }
};
int main() {
  std::cout << Solution().minTransfers(
    {
        {0,1,1}, {1,2,1}, {2, 0, 1}
    }
  ) << std::endl;
  return 0;
}
