#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
class Solution {
public:
  std::string alienOrder(const std::vector<std::string>& words) {
    std::vector<std::vector<int>> edges(26);
    std::vector<bool> exist(26, false);
    std::vector<int> indegree(26, 0);
    for (auto word : words) {
      for (auto c : word) {
        exist[c - 'a'] = true;
      }
    }
    for (int i = 0; i < words.size() - 1; i ++) {
      int j;
      for (j = 0; j < words[i].size() && j < words[i + 1].size(); j ++) {
        if (words[i][j] != words[i + 1][j]) {
          edges[words[i][j] - 'a'].push_back(words[i + 1][j] - 'a');
          indegree[words[i + 1][j] - 'a'] ++;
          break;
        }
      }
      if (j == words[i + 1].size() && j < words[i].size()) {
        return "";
      }
    }
    std::queue<int> zero_degree_queue;
    for (int i = 0; i < 26; i ++) {
      if (indegree[i] == 0 && exist[i]) {
        zero_degree_queue.push(i);
      }
    }
    std::string result;
    for (;!zero_degree_queue.empty();) {
      int f = zero_degree_queue.front();
      result.push_back('a' + f);
      zero_degree_queue.pop();
      for (auto to : edges[f]) {
        if (--indegree[to] == 0) {
          zero_degree_queue.push(to);
        }
      }
    }
    return std::any_of(indegree.begin(), indegree.end(), [](int a) {
      return a != 0;
    }) ? "" :result;
  }
};
int main() {
  std::cout << Solution().alienOrder({

    "wertf",
    "wer"
  }) << std::endl;
  return 0;
}
