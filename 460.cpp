#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <cassert>
#include <list>
class LFUCache {
  //freqlist :: [(freq, [key])]
  using freqlist_t = std::list<std::pair<int, std::list<int>>>;
  struct node {
    int v;
    freqlist_t::iterator freqit;
    std::list<int>::iterator listit;
  };
  //kv :: int -> (v, freqit, listit)
  using kv_t = std::unordered_map<int, node>;
  kv_t kv;
  freqlist_t freqlist;
  //does not invalidate it
  void use(kv_t::iterator it) {
    auto& nd = it->second;
    nd.freqit->second.erase(nd.listit);
    auto nextfreqit = std::next(nd.freqit);
    if (nextfreqit == freqlist.end() ||
        nextfreqit->first != nd.freqit->first + 1) {
          nextfreqit = freqlist.insert(nextfreqit, {nd.freqit->first + 1, {}});
    }
    if (nd.freqit->second.empty()) {
      freqlist.erase(nd.freqit);
    }
    it->second.freqit = nextfreqit;
    nextfreqit->second.push_back(it->first);
    it->second.listit = std::prev(nextfreqit->second.end());
  }
  void evict() {
    kv.erase(freqlist.front().second.front());
    freqlist.front().second.pop_front();
    if (freqlist.front().second.empty()) {
      freqlist.pop_front();
    }
  }
  int capacity;
public:
    LFUCache(int capacity) : capacity(capacity) {

    }


    int get(int key) {
      auto it = kv.find(key);
      if (it == kv.end()) {
        return -1;
      } else {
        use(it);
        return it->second.v;
      }
    }

    void put(int key, int value) {
      if (capacity == 0) {
        return;
      }
      auto it = kv.find(key);
      if (it == kv.end()) {
        if (capacity == kv.size()) {
          evict();
        }
        if (freqlist.empty() || freqlist.front().first != 0) {
          freqlist.emplace_front(0, std::list<int>());
        }
        freqlist.front().second.push_back(key);
        kv.insert({key, {value, freqlist.begin(), std::prev(freqlist.front().second.end())}});
      } else {
        it->second.v = value;
        use(it);
      }
    }
};
int main() {
  LFUCache cache(3);
  cache.put(2, 2);
  cache.put(1, 1);
  std::cout << cache.get(2) << std::endl;       // returns 1
  std::cout << cache.get(1) << std::endl;       // returns 1
  std::cout << cache.get(2) << std::endl;       // returns 1
  cache.put(3, 3);    // evicts key 2
  cache.put(4, 4);    // evicts key 1.
  std::cout << cache.get(3) << std::endl;       // returns -1 (not found)
  std::cout << cache.get(4) << std::endl;       // returns 4
  return 0;
}
