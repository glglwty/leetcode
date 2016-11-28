#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iterator>
class Solution {
  struct trie_node {
    trie_node* c[26], *p;
    std::vector<int> end_of;
    trie_node() : p(nullptr) {
      std::fill(std::begin(c), std::end(c), nullptr);
    }
  } root;
  void trie_insert(trie_node* nd, const std::string& word, int word_id,  int pos) {
    if (pos == word.size()) {
      nd->end_of.push_back(word_id);
      return;
    }
    auto& child = nd->c[word[pos] - 'a'];
    if (!child) {
      child = new trie_node;
      child->p = nd;
    }
    trie_insert(child, word, word_id, pos + 1);
  }
  std::vector<int> seq;
  std::vector<trie_node*> trie_pos;
  template<typename T>
  void find_prefix(trie_node* prefix, const T& emit) {
    for (auto id : prefix->end_of) {
      emit(id);
    }
    for (auto c : prefix->c) {
      if (c) {
        find_prefix(c, emit);
      }
    }
  }
  void dfs(int row, const std::vector<std::string>& words, std::vector<std::vector<std::string>>& result) {
    if (row == words[0].size()) {
      result.push_back({});
      for (auto id : seq) {
        result.back().push_back(words[id]);
      }
      return;
    }
    find_prefix(trie_pos[row], [&](int cand) {
      auto& word = words[cand];
      for (int i = row + 1; i < words[0].size(); i ++) {
        if (!trie_pos[i]->c[word[i] - 'a']) {
          return;
        }
      }
      for (int i = row + 1; i < words[0].size(); i ++) {
        trie_pos[i] = trie_pos[i]->c[word[i] - 'a'];
      }
      seq.push_back(cand);
      dfs(row + 1, words, result);
      seq.pop_back();
      for (int i = row + 1; i < words[0].size(); i ++) {
        trie_pos[i] = trie_pos[i]->p;
      }
    });
  }
public:
  std::vector<std::vector<std::string>> wordSquares(const std::vector<std::string>& words) {
    if (words.empty()) {
      return {};
    }
    for (int i = 0; i < words.size(); i ++) {
      trie_insert(&root, words[i], i, 0);
    }
    std::vector<std::vector<std::string>> result;
    used.resize(words.size(), false);
    trie_pos.resize(words[0].size(), &root);
    dfs(0, words, result);
    return result;
  }
};
int main() {
  auto result = Solution().wordSquares({"abat","baba","atan","atal"});
  for (auto& sol : result) {
    std::copy(sol.begin(), sol.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
    std::cout << std::endl;
  }
  return 0;
}
