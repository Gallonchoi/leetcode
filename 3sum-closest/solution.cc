#include <vector>
#include <algorithm>

using namespace std;

class solution {
 public:
  int threesumclosest(vector<int>& nums, int target) {
    vector<int> numbers(nums.begin(), nums.end());
    sort(numbers.begin(), numbers.end());
    if (numbers.size() <= 3) {
      return accumulate(numbers.begin(), numbers.end(), 0);
    }

    int result = numbers[0] + numbers[1] + numbers[2];
    unsigned len = numbers.size();
    for (unsigned i = 0; i < len - 2; ++i) {
      unsigned j = i + 1;
      unsigned k = len - 1;
      while (j < k) {
        const int sum = numbers[i] + numbers[j] + numbers[k];

        if (abs(target - sum) < abs(target - result)) {
          result = sum;
        }
        sum > target ? --k : ++j;
      }
    }
    return result;
  }
};
