#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <unordered_set>
using std::vector;
using std::string;
using std::pair;
class Solution {
  void dfs(vector<vector<int>>& adj, vector<bool>& visited, int id) {
    visited[id] = true;
    for (auto that : adj[id]) {
      if (!visited[that]) {
        dfs(adj, visited, that);
      }
    }
  }
public:
  int countComponents(int n, vector<pair<int, int>>& edges) {
    vector<vector<int>> adj(n);
    for (auto& edge : edges) {
      adj[edge.first].push_back(edge.second);
      adj[edge.second].push_back(edge.first);
    }
    vector<bool> visited(n, false);
    int result = 0;
    for (int i = 0; i < n; i ++) {
      if (!visited[i]) {
        result ++;
        dfs(adj, visited, i);
      }
    }
    return result;
  }
};
int main() {

}
