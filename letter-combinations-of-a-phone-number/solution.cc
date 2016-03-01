#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> letterCombinations(const string &digits) {
    if (digits.empty()) return vector<string>{};
    string dtoa[]{"0",   "1",   "abc",  "def", "ghi",
                  "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> result{""};
    for (const auto digit : digits) {
      vector<string> temp;
      auto chars = dtoa[digit - '0'];
      for (auto c : chars) {
        for (auto r : result) {
          temp.push_back(r + c);
        }
      }
      result.swap(temp);
    }
    return result;
  }
};
