#include <iostream>
#include <vector>
#include <algorithm>
class Solution {
public:
  int minArea(const std::vector<std::vector<char>>& image, int x, int y) {
    typedef std::pair<int, int> pi;
    pi ds[] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    auto max_span = [&](const pi& p, const pi& d) -> int{
      if (d.first == 0) {
        return d.second > 0 ? image[0].size() - p.second - 1 : p.second;
      } else {
        return d.first > 0 ? image.size() - p.first - 1 : p.first;
      }
    };
    auto at = [&image](const pi& p) {
      return image[p.first][p.second];
    };
    auto valid = [&image](const pi& p) {
      return p.first >= 0 && p.second >= 0 && p.first < image.size() && p.second < image[0].size();
    };
    auto add = [](const pi& a, const pi& b) -> pi {
      return {a.first + b.first, a.second + b.second};
    };
    auto multi = [](const pi& a, int b) -> pi {
      return {a.first * b, a.second * b};
    };
    int span[4];
    for (int i = 0; i < 4; i ++) {
      auto& d = ds[i];
      int l = 0, r = max_span({x, y}, d);
      while (l < r) {
        int m = (l + r + 1) / 2;
        auto dest = add({x, y}, multi(d, m));
        bool found = false;
        for (auto dd : {ds[(i + 1) % 4], ds[(i + 3) % 4]}) {
          if (found) {
            break;
          }
          for (auto curr = dest; valid(curr); curr = add(curr, dd)) {
            if (at(curr) == '1') {
              found = true;
              break;
            }
          }
        }
        if (found) {
          l = m;
        } else {
          r = m - 1;
        }
      }
      std::cerr << l << std::endl;
      span[i] = l;
    }
    return (span[0] + span[2] + 1) * (span[1] + span[3] + 1);
  }
};
int main() {
  std::cout << Solution().minArea({
    {'0', '0', '1', '0'},
    {'0', '1', '1', '0'},
    {'0', '1', '0', '0'}
  }, 0, 2) << std::endl;
  return 0;
}
