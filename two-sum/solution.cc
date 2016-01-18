#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> hash;
    for (int i = 0; i < nums.size(); ++i) {
      const int second = target - nums[i];
      if (hash.find(second) != hash.end()) {
        return vector<int>{hash[second] + 1, i + 1};
      }
      hash[nums[i]] = i;
    }
  }
};
