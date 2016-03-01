#include <vector>

using namespace std;

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    unsigned len = nums.size();
    if (len <= 1) return len;
    unsigned x, y = 1;
    for (x = 1; x < len; ++x) {
      if (nums[x] != nums[x - 1]) nums[y++] = nums[x];
    }
    return y;
  }
};
