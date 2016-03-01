#include <string>

using namespace std;

class Solution {
 public:
  int strStr(string haystack, string needle) {
    if (needle.empty()) return 0;
    const auto m = haystack.length(), n = needle.length();
    if (n > m) return -1;
    for (unsigned i = 0; i < m - n + 1; ++i) {
      for (unsigned j = 0; j < n; ++j) {
        if (haystack[i + j] != needle[j]) break;
        if (j == n - 1) return i;
      }
    }
    return -1;
  }
};
