#include <vector>

using namespace std;

class Solution {
 public:
  int removeElement(vector<int>& nums, int val) {
    if (nums.empty()) return nums.size();

    unsigned i, j;
    const auto len = nums.size();

    for (i = j = 0; i < len; ++i) {
      if (nums[i] != val) {
        nums[j++] = nums[i];
      }
    }
    return j;
  }
};
