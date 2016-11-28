#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <algorithm>
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Codec {
  template<typename F>
  void serialize_insert(TreeNode* root, F&& f) {
    if (root == nullptr) {
      f("nil ");
    } else {
      f(std::string("node ") + std::to_string(root->val) + " ");
      serialize_insert(root->left, f);
      serialize_insert(root->right, f);
    }
  }
public:
  // Encodes a tree to a single string.
  std::string serialize(TreeNode* root) {
    std::string result;
    serialize_insert(root, [&result](std::string&& that) {
      result += std::move(that);
    });
    return result;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(const std::string& data) {
    TreeNode* root;
    std::stack<TreeNode**> s;
    s.push(&root);
    std::stringstream ss(data);
    while (!s.empty()) {
      std::string buf;
      ss >> buf;
      if (buf == "nil") {
        *s.top() = nullptr;
        s.pop();
      } else {
        int val;
        ss >> val;
        auto t = new TreeNode(val);
        *s.top() = t;
        s.pop();
        s.push(&t->right);
        s.push(&t->left);
      }
    }
    return root;
  }
};
void traverse(TreeNode* t) {
  if (t == nullptr) {
    std::cerr << "nil";
    return;
  }
  std::cerr << "(" << t->val << ' ';
  traverse(t->left);
  traverse(t->right);
  std::cerr << ")";
}
int main() {
  TreeNode n1(1), n2(2), n3(3), n4(4), n5(5);
  n1.left = &n2;
  n1.right = &n3;
  n3.left = &n4;
  n3.right = &n5;
  auto r = Codec().serialize(&n1);
  std::cerr << r << std::endl;
  auto t = Codec().deserialize(r);
  traverse(t);
  return 0;
}
