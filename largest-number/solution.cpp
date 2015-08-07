// Given a list of non negative integers, arrange them such that they form the largest number.

// For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

// Note: The result may be very large, so you need to return a string instead of an integer.


#include <string>
#include <vector>
#include <algorithm>


using std::string;
using std::vector;
using std::sort;
using std::to_string;


class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b) {
                return to_string(a) + to_string(b) > to_string(b) + to_string(a);
            });
        string ans;
        unsigned idx;
        for(idx = 0; idx < nums.size(); ++ idx) {
            ans += to_string(nums[idx]);
        }
        return ans[0] == '0' ? "0" : ans;
    }
};
