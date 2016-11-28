#include <iostream>
#include <algorithm>
#include <vector>
class Solution {
  std::vector<int> parent;
  int m, n;
  typedef std::pair<int, int> pi;
  int to1d(const pi& p) {
    return p.first * n + p.second;
  }
  pi from1d(int x) {
    return {x / n, x % n};
  }
  bool valid(const pi& p) {
    return p.first >= 0 && p.second >= 0 && p.first < m && p.second < n;
  }
  pi add(const pi& a, const pi& b) {
    return {a.first + b.first, a.second + b.second};
  }
  bool younion(int a, int b) {
    int pa = find(a), pb = find(b);
    if (pa != pb) {
      parent[pa] = pb;
      return true;
    } else {
      return false;
    }
  }
  int find(int a) {
    if (parent[a] == -1) {
      return -1;
    }
    if (parent[a] != a) {
      parent[a] = find(parent[a]);
    }
    return parent[a];
  }

public:
  std::vector<int> numIslands2(int m, int n,
    const std::vector<std::pair<int, int>>& positions) {
    this->m = m;
    this->n = n;
    std::vector<int> result;
    int cur_num = 0;
    pi ds[] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    parent.resize(m * n, -1);
    for (auto& p : positions) {
      auto p1d = to1d(p);
      parent[p1d] = p1d;
      cur_num ++;
      for (auto& d : ds) {
        auto neigh = add(p, d);
        if (valid(neigh)) {
          auto n1d = to1d(neigh);
          if (find(n1d) != -1) {
            if (younion(n1d, p1d)) {
              cur_num --;
            }
          }
        }
      }
      result.push_back(cur_num);
    }
    return result;
  }
};
int main() {
  auto r = Solution().numIslands2(3, 3, {{0,0}, {0,1}, {1,2}, {2,1}});
  std::copy(r.begin(), r.end(), std::ostream_iterator<int>(std::cout, " "));
  return 0;
}
