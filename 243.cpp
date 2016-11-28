#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int shortestDistance(const vector<string>& words, string word1, string word2) {
      int lastword1pos = -1, lastword2pos = -1, answer = numeric_limits<int>::max();
      for (int i = 0; i < words.size(); i ++) {
        if (words[i] == word1) {
          lastword1pos = i;
          if (lastword2pos != -1) {
            answer = min(answer, i - lastword2pos);
          }
        } else if (words[i] == word2) {
          lastword2pos = i;
          if (lastword1pos != -1) {
            answer = min(answer, i - lastword1pos);
          }
        }
      }
      return answer;
    }
};
int main() {
  cout << Solution().shortestDistance({"practice", "makes", "perfect", "coding", "makes"}, "makes", "coding");
  return 0;
}
