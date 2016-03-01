#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
 public:
  vector<vector<int> > fourSum(vector<int>& nums, int target) {
    vector<vector<int> > result;
    if (nums.size() < 4) return result;

    vector<int> numbers(nums.begin(), nums.end());
    sort(numbers.begin(), numbers.end());

    const unsigned len = numbers.size();
    for (unsigned i = 0; i < len - 3; ++i) {
      if (i > 0 && numbers[i] == numbers[i - 1]) continue;
      if (accumulate(numbers.begin() + i, numbers.begin() + i + 4, 0) > target)
        break;
      if (numbers[i] + numbers[len - 3] + numbers[len - 2] + numbers[len - 1] <
          target)
        continue;
      for (unsigned j = i + 1; j < len - 2; ++j) {
        if (j > i + 1 && numbers[j] == numbers[j - 1]) continue;
        if (numbers[i] + numbers[j] + numbers[j + 1] + numbers[j + 2] > target)
          break;
        if (numbers[i] + numbers[j] + numbers[len - 2] + numbers[len - 1] <
            target)
          continue;
        unsigned k = j + 1;
        unsigned l = len - 1;
        while (k < l) {
          if (k > j + 1 && numbers[k] == numbers[k - 1]) {
            ++k;
            continue;
          }
          const int sum = numbers[i] + numbers[j] + numbers[k] + numbers[l];

          if (sum == target) {
            vector<int> item{numbers[i], numbers[j], numbers[k], numbers[l]};
            result.push_back(item);
          }

          sum > target ? --l : ++k;
        }
      }
    }
    return result;
  }
};

int main(void) {
  Solution s;
  vector<int> nums{0, 0, 0, 0};
  auto rs = s.fourSum(nums, 0);
  for (auto& r : rs) {
    for (auto num : r) {
      cout << num << " ";
    }
  }
  cout << endl;
  return 0;
}
