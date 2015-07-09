#include <iostream>
#include <string>

using std::string;

class Solution {
public:
    Solution() {}

    int titleToNumber(string s) {
        int idx;
        long sum, count;
        sum = 0;
        count = 1;
        for(idx = s.size() - 1; idx >= 0; idx --) {
            sum += (s[idx] - 'A' + 1) * count;
            count *= 26;
        }
        return sum;
    }

    void toNumber(const string &s) {
        std::cout << s << " == " << titleToNumber(s) << std::endl;
    }
};


int main(void) {
    Solution A;
    A.toNumber("A");
    A.toNumber("B");
    A.toNumber("AA");
    A.toNumber("AAA");
    return 0;
}
