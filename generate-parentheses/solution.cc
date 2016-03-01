#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> generateParenthesis(int n) {
    vector<string> result;
    generateProcess(result, "", n, 0);

    return result;
  }

  void generateProcess(vector<string>& v, const string& str, int left,
                       int right) {
    if (left == 0 && right == 0) {
      v.push_back(str);
      return;
    }

    if (right > 0) generateProcess(v, str + ")", left, right - 1);
    if (left > 0) generateProcess(v, str + "(", left - 1, right + 1);
  }
};
