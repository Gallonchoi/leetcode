// Given a string containing only digits, restore it by returning all possible valid IP address combinations.

// For example:
// Given "25525511135",

// return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)


#include <string>
#include <vector>

using std::string;
using std::vector;


class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        std::vector<string> ans;
        unsigned len = s.length();
        unsigned i, j, k;
        for(i = 1; i < 4 && i < len - 2; ++ i) {
            for(j = i + 1; j < i + 4 && j < len - 1; ++ j) {
                for(k = j + 1; k < j + 4 && k < len; ++ k) {
                    string s1, s2, s3, s4;
                    s1 = s.substr(0, i);
                    s2 = s.substr(i, j - i);
                    s3 = s.substr(j, k - j);
                    s4 = s.substr(k);
                    if(isValid(s1) && isValid(s2) && isValid(s3) && isValid(s4)) {
                        ans.push_back(s1 + "." + s2 + "." + s3 + "." + s4);
                    }
                }
            }
        }
        return ans;
    }

    inline bool isValid(const string& s){
        if(s.length() > 3 || s.length() == 0 || (s[0] == '0' && s.length() > 1) || toInt(s) > 255) {
            return false;
        } else {
            return true;
        }
    }

    inline int toInt(const string& s) {
        int ans;
        unsigned idx;
        ans = 0;
        for(idx = 0; idx < s.length(); ++ idx) {
            ans = ans * 10 + s[idx] - '0';
        }
        return ans;
    }
};
