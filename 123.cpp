#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(const vector<int>& prices) {
      int holdingFirst = -100000, finishedFirst = -100000, holdingSecond = -100000, finishedSecond = -1000000;
      for (auto price : prices) {
        finishedSecond = max(finishedSecond, holdingSecond + price);
        holdingSecond = max(holdingSecond, finishedFirst - price);
        finishedFirst = max(finishedFirst, holdingFirst + price);
        holdingFirst = max(holdingFirst, -price);
      }
      return max(0, max(finishedFirst, finishedSecond));
    }
};
int main() {
  return 0;
}
