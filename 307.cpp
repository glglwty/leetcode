#include <iostream>
#include <vector>
#include <algorithm>
class NumArray {
  std::vector<int> s;
  int size, pow_align;
public:
  NumArray(const std::vector<int> &nums) {
    size = nums.size();
    pow_align = 1;
    while (pow_align < nums.size()) {
      pow_align *= 2;
    }
    s = std::vector<int>(pow_align * 2, 0);
    std::copy(nums.begin(), nums.end(), s.begin() + pow_align);
    for (int i = pow_align - 1; i > 0; i --) {
      s[i] = s[i * 2] + s[i * 2 + 1];
    }
  }

  void update(int i, int val) {
    int l = 0, r = pow_align, delta = val - s[pow_align + i], t = 1;
    while (true) {
      s[t] += delta;
      if (l + 1 == r) {
        break;
      }
      int m = (l + r) / 2;
      if (i < m) {
        r = m;
        t = t * 2;
      } else {
        l = m;
        t = t * 2 + 1;
      }
    }
  }
  int sum(int t, int i, int j, int l, int r) {
    if (i <= l && j >= r) {
      return s[t];
    }
    int m = (l + r) / 2, su = 0;
    if (i < m) {
      su += sum(t * 2, i, j, l, m);
    }
    if (j > m) {
      su += sum(t * 2 + 1, i, j, m, r);
    }
    //std::cout << t << ' ' << i << ' '  << j << ' ' << l << ' ' << r << ' ' << su << std::endl;
    return su;
  }

  int sumRange(int i, int j) {
    return sum(1, i, j + 1, 0, pow_align);
  }
};

int main() {
  NumArray a({-1});
  std::cout << a.sumRange(0, 0) << std::endl;
  a.update(0, 1);
  std::cout << a.sumRange(0, 0) << std::endl;
  return 0;
}
