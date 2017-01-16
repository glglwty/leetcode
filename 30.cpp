#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <iterator>
using namespace std;
class Solution {
public:
  std::vector<int> findSubstring(const std::string& s, const std::vector<std::string>& words) {
    std::unordered_map<std::string, int> dict, count;
    for (auto& word : words) {
      dict[word] ++;
    }
    std::vector<int> result;
    for (int i = 0; i < words[0].size() && i < s.size(); i ++) {
      count.clear();
      for (int j = i, k = i; j + words[0].size() <= s.size(); j += words[0].size()) {
        auto substr = s.substr(j, words[0].size());
        auto dit = dict.find(substr);
        if (dit == dict.end()) {
          count.clear();
          k = j + words[0].size();
        } else {
          count[substr] ++;
          auto cit = count.find(substr);
          while (cit->second > dit->second) {
            count[s.substr(k, words[0].size())] --;
            k += words[0].size();
          }
        }
        if ((j - k) == (words.size() - 1) * words[0].size()) {
          result.push_back(k);
        }
      }
    }
    return result;
  }
};
int main() {
  auto r = Solution().findSubstring("wordgoodgoodgoodbestword", {"word","good","best","good"});
  std::copy(r.begin(), r.end(), std::ostream_iterator<int>(std::cout, " "));
  return 0;
}
