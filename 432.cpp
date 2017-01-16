#include <iostream>
#include <string>
#include <list>
#include <unordered_map>
class AllOne {
public:
  using row_t = std::list<std::string>;
  using book_t = std::list<std::pair<int, row_t>>;
  book_t value_list; // [(freq, [key])]
  std::unordered_map<std::string, std::pair<book_t::iterator, row_t::iterator>> kv;
  /** Initialize your data structure here. */
  AllOne() {}

  /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
  void inc(const std::string& key) {
    auto it = kv.find(key);
    if (it == kv.end()) {
      if (value_list.empty() || value_list.front().first != 1) {
        value_list.push_front({1, {}});
      }
      value_list.front().second.push_front(key);
      kv.insert(it, {key, {value_list.begin(), value_list.front().second.begin()}});
    } else {
      auto& rowit = it->second.first;
      auto& colit = it->second.second;
      rowit->second.erase(colit);
      auto next_row_it = std::next(rowit);
      if (next_row_it == value_list.end() ||
          next_row_it->first != rowit->first + 1) {
        value_list.insert(next_row_it, {rowit->first + 1, {}});
        next_row_it = std::next(rowit);
      }
      if (rowit->second.empty()) {
        value_list.erase(rowit);
      }
      rowit = next_row_it;
      rowit->second.push_front(key);
      colit = rowit->second.begin();
    }
  }

  /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
  void dec(const std::string& key) {
    auto it = kv.find(key);
    if (it == kv.end()) {
      return;
    }
    auto& rowit = it->second.first;
    auto& colit = it->second.second;
    rowit->second.erase(colit);
    if (rowit->first == 1) {
      if (rowit->second.empty()) {
        value_list.pop_front();
      }
      kv.erase(it);
    } else {
      if (rowit == value_list.begin() || std::prev(rowit)->first != rowit->first - 1) {
        value_list.insert(rowit, {rowit->first - 1, {}});
      }
      auto prev_row_it = std::prev(rowit);
      if (rowit->second.empty()) {
        value_list.erase(rowit);
      }
      rowit = prev_row_it;
      rowit->second.push_front(key);
      colit = rowit->second.begin();
    }
  }

  /** Returns one of the keys with maximal value. */
  std::string getMaxKey() {
    return kv.empty() ? "" : value_list.back().second.front();
  }

  /** Returns one of the keys with Minimal value. */
  std::string getMinKey() {
    return kv.empty() ? "" : value_list.front().second.front();
  }
};
int main() {
  AllOne obj{};
  obj.inc("1");
  obj.inc("2");
  obj.dec("2");
  auto param_3 = obj.getMaxKey();
  auto param_4 = obj.getMinKey();
  std::cout << param_3 << std::endl << param_4 << std::endl;
  return 0;
}
