#include <iostream>
#include <algorithm>
struct RandomListNode {
  int label;
  RandomListNode *next, *random;
  RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
class Solution {
public:
  RandomListNode *copyRandomList(RandomListNode *head) {
    if (head == nullptr) {
      return nullptr;
    }
    RandomListNode* prev = nullptr, *newhead = nullptr;
    for (auto nd = head; nd != nullptr;) {
      auto dd = new RandomListNode(nd->label);
      dd->random = nd->random;
      dd->next = nd->next;
      nd->next = dd;
      nd = dd->next;
    }
    newhead = head->next;
    for (auto nd = newhead; nd; nd = nd->next ? nd->next->next : nullptr) {
      if (nd->random) {
        nd->random = nd->random->next;
      }
    }
    for (auto nd = head; nd != nullptr; nd = nd->next) {
      auto dd = nd->next;
      auto ddnext = dd->next ? dd->next->next : nullptr;
      nd->next = dd->next;
      dd->next = ddnext;
    }
    return newhead;
  }
};
int main() {
  RandomListNode a0(0), a1(1), a2(2), a3(3);
  a0.random = &a0;
  Solution().copyRandomList(&a0);
  return 0;
}
