#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
class RandomizedSet {
  std::vector<int> vec;
  std::unordered_map<int, int> hash;
public:

  /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
  bool insert(int val) {
    if (hash.find(val) == hash.end()) {
      hash[val] = vec.size();
      vec.push_back(val);
      return true;
    }
    return false;
  }

  /** Removes a value from the set. Returns true if the set contained the specified element. */
  bool remove(int val) {
    auto it = hash.find(val);
    if (it != hash.end()) {
      hash[vec.back()] = it->second;
      std::swap(vec[it->second], vec.back());
      vec.pop_back();
      hash.erase(it);
      return true;
    }
    return false;
  }

  /** Get a random element from the set. */
  int getRandom() {
    return vec[rand() % vec.size()];
  }
};

int main() {
  RandomizedSet obj;
  std::cout << obj.insert(1) << " " << obj.remove(2) << " " << obj.getRandom() << std::endl;
  return 0;
}
