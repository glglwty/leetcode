#include <iostream>
#include <algorithm>
#include <vector>
#include <memory>
class Solution {
  struct trie_node {
    std::unique_ptr<trie_node> ch[26];
    int end_of = -1;
    void insert(std::string::const_iterator s, std::string::const_iterator e, int tag) {
      if (s == e) {
        end_of = tag;
      } else {
        if (ch[*s - 'a'] == nullptr) {
          ch[*s - 'a'].reset(new trie_node);
        }
        ch[*s - 'a']->insert(s + 1, e, tag);
      }
    }
  };
  template<typename F>
  void search(
    const std::vector<std::vector<char>>& board,
    std::vector<std::vector<bool>>& used,
    int x,
    int y,
    trie_node& cur_node,
    F&& f) {
    constexpr int ds[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    if (auto ch = cur_node.ch[board[x][y] - 'a'].get()) {
      //std::cerr << x << ' ' << y << ' ' << std::endl;
      used[x][y] = true;
      if (ch->end_of != -1) {
        f(ch->end_of);
      }
      for (int dit = 0; dit < 4; dit ++) {
        int xx = x + ds[dit][0], yy = y + ds[dit][1];
        if (xx >= 0 && yy >= 0 && xx < board.size() && yy < board[0].size() && !used[xx][yy]) {
          search(board, used, xx, yy, *ch, f);
        }
      }
      used[x][y] = false;
    }
  }
public:
  std::vector<std::string> findWords(
    const std::vector<std::vector<char>>& board,
    const std::vector<std::string>& words) {
    trie_node root;
    for (int i = 0; i < words.size(); i ++) {
      root.insert(words[i].begin(), words[i].end(), i);
    }
    std::vector<bool> found(words.size(), false);
    std::vector<std::string> result;
    std::vector<std::vector<bool>> used(board.size(), std::vector<bool>(board[0].size(), false));
    for (int i = 0; i < board.size(); i ++) {
      for (int j = 0; j < board[i].size(); j ++) {
        search(board, used, i, j, root, [&](int tag) {
          if (!found[tag]) {
            found[tag] = true;
            result.push_back(words[tag]);
          }
        });
      }
    }
    return result;
  }
};
int main() {
  auto r = Solution().findWords({
    {'a','a'},
  },
  {"aaa"});
  std::copy(r.begin(), r.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
  return 0;
}
