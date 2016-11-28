#include <iostream>
#include <algorithm>

struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
class Solution {
public:
  void connect(TreeLinkNode *root) {
    if (root == nullptr) {
      return;
    }
    root->next = nullptr;
    TreeLinkNode *last_level, *curr_level, *curr_level_start = root;
    while(true) {
      last_level = curr_level_start;
      curr_level = nullptr;
      while (last_level != nullptr) {
        if (last_level->left != nullptr) {
          if (curr_level == nullptr) {
            curr_level = curr_level_start = last_level->left;
          } else {
            curr_level = curr_level->next = last_level->left;
          }
        }
        if (last_level->right != nullptr) {
          if (curr_level == nullptr) {
            curr_level = curr_level_start = last_level->right;
          } else {
            curr_level = curr_level->next = last_level->right;
          }
        }
        last_level = last_level->next;
      }
      if (curr_level != nullptr) {
        curr_level->next = nullptr;
      } else {
        break;
      }
    }
  }
};
int main() {
  TreeLinkNode root(0);
  Solution().connect(&root);
  return 0;
}
