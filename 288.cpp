#include <iostream>
#include <vector>
#include <map>
class ValidWordAbbr {
  std::map<int, std::string> lengths[26][26];
  bool hasempty = false;
public:
  ValidWordAbbr(const std::vector<std::string> &dictionary) {
    for (auto& word : dictionary) {
      if (word == "") {
        continue;
      }
      auto& m = lengths[word.front() - 'a'][word.back() - 'a'];
      auto it = m.find(word.size());
      if (it == m.end()) {
        m.insert(it, {word.size(), word});
      } else if (it->second != word){
        it->second = "";
      }
    }
  }

  bool isUnique(const std::string& word) {
    if (word == "") {
      return true;
    }
    auto m = lengths[word.front() - 'a'][word.back() - 'a'];
    auto it = m.find(word.size());
    if (it == m.end() || it->second == word) {
      return true;
    } else {
      return false;
    }
  }
};

int main () {
  ValidWordAbbr vwa({"hello"});
  std::string queries[]{"hello"};
  for (auto& q : queries) {
    std::cout << vwa.isUnique(q) << std::endl;
  }
  return 0;
}
