#include <iostream>
#include <algorithm>
#include <vector>
#include <memory>
#include <string>
#include <map>
class Solution {
public:
    struct node {
        std::unique_ptr<node> c[26];
        std::vector<int> palin_befores; //index of words whose substr(not empty) before this node is a palindrome
        std::vector<int> end_ats;       //index of words that ends here
    };
    //whetere s[st, ed) is a palindrome
    bool isPalindrome(const std::string& s, int st, int ed) {
        if (st == ed || st + 1 == ed) {
            return true;
        }
        for (int i = st, j = ed - 1; i < j; i ++, j --) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }
    void addWord(node* root, const std::vector<std::string>& words, int idx) {
        node* current = root;
        auto& s = words[idx];
        for (int i = s.size() - 1; i >= 0; i --) {
            if (isPalindrome(s, 0, i + 1)) {
                current->palin_befores.push_back(idx);
            }
            if (!current->c[s[i] - 'a']) {
              auto next = new node();
              current->c[s[i]-'a'].reset(next);
              current = next;
            } else {
              current = current->c[s[i] - 'a'].get();
            }
        }
        current->end_ats.push_back(idx);
    }
    std::vector<std::vector<int>> palindromePairs(const std::vector<std::string>& words) {
        node root;
        std::vector<std::vector<int>> result;
        for (int i = 0; i < words.size(); i ++) {
            addWord(&root, words, i);
        }
        for (int i = 0; i < words.size(); i ++) {
            auto& s = words[i];
            node* current = &root;
            for (int j = 0; j <= s.size(); j ++) {
                if (j == s.size()) {
                    for (auto idx : current->palin_befores) {
                        if (i != idx) {
                            result.push_back({i, idx});
                        }
                    }
                    for (auto idx : current->end_ats) {
                        if (i != idx) {
                            result.push_back({i, idx});
                        }
                    }
                } else  {
                    if (isPalindrome(s, j , s.size())) {
                        for (auto idx : current->end_ats) {
                            if (i != idx) {
                                result.push_back({i, idx});
                            }
                        }
                    }
                    if (current->c[s[j] - 'a']) {
                      current = current->c[s[j] - 'a'].get();
                    } else {
                      break;
                    }
                }
            }
        }
        return result;
    }
};
int main() {
  auto calcshow = [](const std::vector<std::string>& a) {
      auto r = Solution().palindromePairs(a);
      for (auto& row : r) {
        for (auto elem : row) {
          std::cout << elem << ' ';
        }
        std::cout << std::endl;
      }
  };
  calcshow({"bat", "tab", "cat"});
  calcshow({"abcd", "dcba", "lls", "s", "sssll"});
  return 0;
}
