#include <iostream>
#include <string>
class Solution {
  static constexpr char const* ones[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
  static constexpr char const* tens[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
  static constexpr char const* doubledigit[] = {"None", "None", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
  static constexpr char const* chunkunit[] = {"", "Thousand ", "Million ", "Billion "};
  std::string three_digit(int num) {
    std::string result;
    if (num >= 100) {
      result += ones[num / 100];
      result += " Hundred ";
    }
    num %= 100;
    if (num >= 20) {
      result += doubledigit[num / 10];
      result.push_back(' ');
      if (num % 10 != 0) {
        result += ones[num % 10];
        result.push_back(' ');
      }
    } else if (num >= 10) {
      result += tens[num % 10];
      result.push_back(' ');
    } else if (num != 0) {
      result += ones[num];
      result.push_back(' ');
    }
    return result;
  }
public:
  std::string numberToWords(int num) {
    std::string result;
    if (num == 0) {
      result = "Zero ";
    } else {
      for (int i = 0; i < 4; i ++) {
        auto cur = num % 1000;
        if (cur != 0) {
          result = three_digit(cur) + chunkunit[i] + result;
        }
        num /= 1000;
      }
    }
    result.pop_back();
    return result;
  }
};
constexpr char const* Solution::ones[];
constexpr char const* Solution::tens[];
constexpr char const* Solution::doubledigit[];
constexpr char const* Solution::chunkunit[];
int main() {
  Solution sol;
  std::cout << sol.numberToWords(123) << std::endl
    << sol.numberToWords(12345) << std::endl
    << sol.numberToWords(1234567) << std::endl
    << sol.numberToWords(123000) << std::endl
    << sol.numberToWords(1000010) << std::endl;
}
