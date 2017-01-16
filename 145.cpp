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
  vector<int> postorderTraversal(TreeNode* root) {
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
      if (t->left) {
        s.push(t->left);
      }
      if (t->right) {
        s.push(t->right);
      }
    }
    std::reverse(r.begin(), r.end());
    return r;
  }
};
int main() {

}
