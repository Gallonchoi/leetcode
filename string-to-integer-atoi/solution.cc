#include <string>
#include <iostream>

using namespace std;

class Solution {
 public:
  int myAtoi(string str) {
    const int kMaxInt = 2147483647, kMinInt = -2147483648;
    int sign = 1, base = 0, i = 0;
    while (str[i] == ' ') {
      i++;
    }
    if (str[i] == '-' || str[i] == '+') {
      sign = 1 - 2 * (str[i++] == '-');
    }
    while (str[i] >= '0' && str[i] <= '9') {
      if (base > kMaxInt / 10 || (base == kMaxInt / 10 && str[i] - '0' > 7)) {
        if (sign == 1)
          return kMaxInt;
        else
          return kMinInt;
      }
      base = 10 * base + (str[i++] - '0');
    }
    return base * sign;
  }
};

int main(void) {
  auto s = new Solution;
  auto result = s->myAtoi("      2147483648");
  std::cout << result << std::endl;
  delete s;
  return 0;
}
