#include <vector>
#include <iostream>

using namespace std;

class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty())
      return "";
    else if (strs.size() == 1)
      return strs[0];
    string prefix;
    size_t i = 0;
    while (i < strs[0].length()) {
      const char c = strs[0][i];
      for (size_t j = 1; j < strs.size(); ++j) {
        const string& str = strs[j];
        if (i >= str.length() || str[i] != c) {
          return prefix;
        }
      }
      prefix += c;
      ++i;
    }
    return prefix;
  }
};
