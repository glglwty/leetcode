
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <unordered_set>
using std::vector;
using std::string;
using std::pair;
using std::copy;
using std::back_inserter;
class Codec {
public:
    void insert_integer(string& s, int a) {
        for (int i = sizeof(a) - 1; i >= 0; i --) {
            s.push_back((a >> (i * 8)) & 0xff);
        }
    }
    int parse_integer(const string& s, int& p) {
        int a;
        for (int i = 0; i < sizeof(a); i ++) {
            a <<= 8;
            a += s[p + i];
        }
        p += sizeof(a);
        return a;
    }
    // Encodes a list of strings to a single string.
    string encode(const vector<string>& strs) {
        string r;
        insert_integer(r, strs.size());
        for (auto& str : strs) {
            insert_integer(r, str.size());
            r += str;
        }
        std::cout << r << std::endl;
        return r;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(const string& s) {
        int p = 0;
        vector<string> r(parse_integer(s, p));
        std::cout << r.size() << std::endl;
        for (auto& str : r) {
            int sz = parse_integer(s, p);
            std::cout << sz << std::endl;
            copy(s.begin() + p, s.begin() + p + sz, back_inserter(str));
            p += sz;
            std::cout << str << std::endl;
        }
        return r;
    }
};
int main () {
  auto s =
}
