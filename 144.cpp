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
  vector<int> preorderTraversal(TreeNode* root) {
    std::vector<int> r;
    if (!root) {
        return r;
    }
    std::stack<TreeNode*> s;
    s.push(root);

    while (!s.empty()) {
      auto t = s.top();
      s.pop();
      r.push_back(t->val);
      if (t->right) {
        s.push(t->right);
      }
      if (t->left) {
        s.push(t->left);
      }
    }
    return r;
  }
};
int main() {

}
