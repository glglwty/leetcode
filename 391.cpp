#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
class Solution {
public:
  bool isRectangleCover(const std::vector<std::vector<int>>& rectangles) {
    int xl = std::numeric_limits<int>::max();
    int yl = std::numeric_limits<int>::max();
    int xu = std::numeric_limits<int>::min();
    int yu = std::numeric_limits<int>::min();
    int area = 0;
    std::vector<std::pair<int, std::pair<int, int>>> events;
    for (auto& rect : rectangles) {
      xl = std::min(xl, rect[0]);
      yl = std::min(yl, rect[1]);
      xu = std::max(xu, rect[2]);
      yu = std::max(yu, rect[3]);
      area += (rect[2] - rect[0]) * (rect[3] - rect[1]);
      events.emplace_back(rect[0] * 2 + 1, std::make_pair(rect[1], rect[3]));
      events.emplace_back(rect[2] * 2, std::make_pair(rect[1], rect[3]));
    }
    if (area != (xu - xl) * (yu - yl)) {
      return false;
    }
    std::sort(events.begin(), events.end());
    std::set<std::pair<int, int>> s;
    for (auto& event : events) {
      if (event.first % 2 == 0) {
        s.erase(event.second);
      } else {
        auto it = s.lower_bound(event.second);
        if ((it != s.end() && it->first < event.second.second) ||
            (it != s.begin() && std::prev(it)->second > event.second.first)) {
              return false;
        }
        s.insert(event.second);
      }
    }
    return true;
  }
};
int main() {
  std::cout << Solution().isRectangleCover(
    {
      {1,1,2,3},
      {1,3,2,4},
      {3,1,4,2},
      {3,2,4,4}
    }
  ) << Solution().isRectangleCover(
    {
      {1,1,3,3},
      {3,1,4,2},
      {3,2,4,4},
      {1,3,2,4},
      {2,3,3,4}
    }
  ) << std::endl;
  return 0;
}
