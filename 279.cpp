#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int numSquares(int n) {
        //least_number[i] is the least number of perfect square numbers which sum to i
        vector<int> least_number(n + 1, 0);
        for (int i = 0; i <= n; i ++) {
            least_number[i] = i;
        }
        for (int i = 0; i * i <= n; i ++) {
            for (int j = i * i; j <= n; j ++) {
                least_number[j] = min(least_number[j], least_number[j - i * i] + 1);
            }
        }
        return least_number[n];
    }
};
int main() {
  cout << Solution().numSquares(13);
  return 0;
}
