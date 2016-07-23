#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int hIndex(const vector<int>& citations) {
      for (int i = citations.size() - 1; i >= 0; i --) {
        if (citations[i] < citations.size() - i) {
          return citations.size() - i - 1;
        }
      }
      return citations.size();
    }
};
int main() {
  cout << Solution().hIndex({0, 1, 3, 5, 6});
  return 0;
}
