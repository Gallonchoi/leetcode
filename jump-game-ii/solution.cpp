// Given an array of non-negative integers, you are initially positioned at the first index of the array.

// Each element in the array represents your maximum jump length at that position.

// Your goal is to reach the last index in the minimum number of jumps.

// For example:
// Given array A = [2,3,1,1,4]

// The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)


#include <vector>

using std::vector;


class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() < 2) {
            return 0;
        } else {
            int level, currentMax, nextMax, idx;
            level = currentMax = nextMax = idx = 0;
            while(currentMax - idx + 1 > 0) {
                ++ level;
                while(idx <= currentMax) {
                    nextMax = max(nums[idx] + idx, nextMax);
                    if(nextMax >= nums.size() - 1) {
                        return level;
                    }
                    ++ idx;
                }
                currentMax = nextMax;
            }
            return 0;
        }
    }

    inline int max(int x, int y) {
        return x > y ? x : y;
    }
};
