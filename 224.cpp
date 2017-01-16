#include <iostream>
#include <stack>
#include <cassert>
class Solution {
public:
  int calculate(const std::string& s) {
    std::stack<char> operators;
    operators.push('+');
    int pos = 0;
    auto jump_space = [&pos, &s]() {
      while (pos < s.size() && s[pos] == ' ') {
        pos ++;
      }
    };
    auto is_digit = [](int ch) {
      return ch >= '0' && ch <= '9';
    };
    int current_result = 0;
    int current_number = 0;
    bool parsing_number = false;
    bool current_positive = true;
    auto fix_sign = [&current_positive](char ch) {
      if (ch == '-') {
        current_positive = !current_positive;
      }
    };
    auto pop_operator = [&operators, &fix_sign]() {
      assert(!operators.empty());
      if (operators.top() != '(') {
        fix_sign(operators.top());
        operators.pop();
      }
    };
    while (pos < s.size() || parsing_number) {
      if (!parsing_number) {
        jump_space();
        if (pos == s.size()) {
          break;
        } else if (is_digit(s[pos])){
          current_number = s[pos] - '0';
          parsing_number = true;
        } else if (s[pos] == ')') {
          assert(!operators.empty() && operators.top() == '(');
          operators.pop();
          pop_operator();
        } else {
          operators.push(s[pos]);
          fix_sign(s[pos]);
        }
        pos ++;
      } else {
        if (pos == s.size() || !is_digit(s[pos])) {
          current_result += current_positive ? current_number : -current_number;
          pop_operator();
          parsing_number = false;
        } else {
          current_number = current_number * 10 + s[pos] - '0';
          pos ++;
        }
      }
    }
    return current_result;
  }
};
int main() {
  std::cout << Solution().calculate("1 + 1") << std::endl;
  std::cout << Solution().calculate(" 2-1 + 2 ") << std::endl;
  std::cout << Solution().calculate("(1+(4+5+2)-3)+(6+8)") << std::endl;
  return 0;
}
