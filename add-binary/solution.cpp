// Given two binary strings, return their sum (also a binary string).
// For example,
// a = "11"
// b = "1"
// Return "100"


#include <string>

using std::string;

class Solution {
public:
    string addBinary(string a, string b) {
        banlanceString(a, b);
        int idx;
        unsigned borrow;
        borrow = 0;
        for(idx = a.length(); idx >= 0; -- idx) {
            a[idx] = a[idx] + b[idx] + borrow - '0';
            borrow = 0;
            if(a[idx] >= '2') {
                borrow = 1;
                a[idx] -= 2;
            }
        }
        if(borrow > 0) {
            a = '1' + a;
        }
        return a;
    }

    void banlanceString(string& a, string& b) {
        if(a.length() > b.length()) {
            string tmp (a.length() - b.length(), '0');
            b = tmp + b;
        } else {
            string tmp (b.length() - a.length(), '0');
            a = tmp + a;
        }
    }
};
