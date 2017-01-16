#include <iostream>
#include <vector>
#include <stack>
using std::vector;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
  vector<int> inorderTraversal(TreeNode* root) {
    std::stack<TreeNode*> s;
    std::vector<int> r;
    for (; root; root = root->left) {
      s.push(root);
    }
    while (!s.empty()) {
      auto t = s.top();
      s.pop();
      r.push_back(t->val);
      for (auto u = t->right; u; u = u->left) {
        s.push(u);
      }
    }
    return r;
  }
};
int main() {

}
