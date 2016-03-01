#include <climits>
#include <algorithm>

using namespace std;

class Solution {
 public:
  int divide(int dividend, int divisor) {
    if (dividend == INT_MIN && divisor == -1) return INT_MAX;

    const bool sign = !((dividend < 0) ^ (divisor < 0));
    auto dvd = labs(dividend);
    const auto dvs = labs(divisor);
    int result = 0;
    while (dvd >= dvs) {
      long long temp = dvs, multiple = 1;
      while (dvd >= (temp << 1)) {
        temp <<= 1;
        multiple <<= 1;
      }

      dvd -= temp;
      result += multiple;
    }
    return sign ? result : -result;
  }
};
