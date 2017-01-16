#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <unordered_set>
using std::vector;
using std::string;
class Solution {
public:
  vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
    sort(words.begin(), words.end(), [](const string&a, const string& b) {
      return a.size() < b.size();
    });
    std::unordered_set<string> dict;
    vector<string> result;
    for (auto& word : words) {
      vector<bool> f{true};
      for (int i = 0; i < word.size(); i ++) {
        f.push_back(false);
        for (int j = 0; j < i; j ++) {
          if (f[j] && dict.find(word.substr(j, i - j + 1)) != dict.end()) {
            f.back() = true;
            break;
          }
        }
      }
      if (f.back() == true) {
        result.push_back(word);
      }
      dict.insert(word);
    }
    return result;
  }
};
int main () {
  vector<string> words{"cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"};
  auto r = Solution().findAllConcatenatedWordsInADict(words);
  std::copy(r.begin(), r.end(), std::ostream_iterator<string>(std::cout, "\n"));
  return 0;
}
