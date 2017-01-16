#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
  TreeNode* find(TreeNode* root, double target, std::stack<TreeNode*>& s) {
    TreeNode *cur = root, *last;
    while (cur != nullptr) {
      s.push(cur);
      last = cur;
      cur = target < cur->val ? cur->left : cur->right;
    }
    return last;
  }
  static TreeNode* left(TreeNode* t) {
    return t->left;
  }
  static TreeNode* right(TreeNode* t) {
    return t->right;
  }
  template<typename T>
  static TreeNode* traverse_from(std::stack<TreeNode*>& s, T&& forward, T&& backward) {
    if (forward(s.top())) {
      for (auto cur = forward(s.top()); cur; cur = backward(cur)) {
        s.push(cur);
      }
      return s.top();
    } else {
      while (true) {
        auto cur = s.top();
        s.pop();
        if (s.empty()) {
          return nullptr;
        }
        if (backward(s.top()) == cur) {
          return s.top();
        }
      }
    }
  }
  template<typename T>
  void find_nodes (T&& f, int k, std::vector<int>& out, std::stack<TreeNode*>& s) {
    for (int i = 0; i < k; i ++) {
      if (auto cur = f(s)) {
        out.push_back(cur->val);
      } else {
        break;
      }
    }
  };
public:
  std::vector<int> closestKValues(TreeNode* root, double target, int k) {
    std::stack<TreeNode*> s, s_save;
    auto node = find(root, target, s);
    std::vector<int> pred_nodes, succ_nodes;
    (node->val <= target ? pred_nodes : succ_nodes).push_back(node->val);
    s_save = s;
    find_nodes([](std::stack<TreeNode*>& s) {
      return traverse_from(s, left, right);
    }, k, pred_nodes, s);
    s = std::move(s_save);
    find_nodes([](std::stack<TreeNode*>& s) {
      return traverse_from(s, right, left);
    }, k, succ_nodes, s);
    std::vector<int> result;
    std::merge(
      pred_nodes.begin(), pred_nodes.end(),
      succ_nodes.begin(), succ_nodes.end(),
      std::back_inserter(result),
      [target](double a, double b) {
        return fabs(a - target) < fabs(b - target);
      }
    );
    result.erase(result.begin() + k, result.end());
    return result;
  }
};
int main() {
  return 0;
}
