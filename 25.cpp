#include <iostream>
#include <algorithm>
#include <vector>
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
  bool hasKNext(ListNode* t, int k) {
    for (; t != nullptr; t = t->next) {
      if (--k == 0) {
        return true;
      }
    }
    return false;
  }
public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode *newhead = nullptr, **pnext = &newhead;
    for (auto t = head; t != nullptr; ) {
      if (hasKNext(t, k)) {
        auto a = t, b = t->next;
        for (int i = 0; i < k - 1; i ++) {
          auto c = b->next;
          b->next = a;
          a = b;
          b = c;
        }
        *pnext = a;
        t->next = nullptr;
        pnext = &t->next;
        t = b;
      } else {
        *pnext = t;
        break;
      }
    }
    return newhead;
  }
};
int main() {
  std::vector<ListNode> nodes;
  for (int i = 0; i < 5; i ++) {
    nodes.emplace_back(i);
  }
  for (int i = 0; i < 4; i ++) {
    nodes[i].next = &nodes[i + 1];
  }
  for (auto t = Solution().reverseKGroup(&nodes[0], 2); t; t = t->next) {
    std::cout << t->val << std::endl;
  }
  return 0;
}
