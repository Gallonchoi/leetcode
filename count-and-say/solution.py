"""Count and Say
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, 312211, 13112221...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
"""

class Solution:
    # @return a string
    def countAndSay(self, n):
        t = '1'
        while n > 1:
            r = ""
            c = 1
            for i in range(1, len(t)):
                if t[i] != t[i-1]:
                    r += str(c) + t[i-1]
                    c = 1
                else:
                    c += 1
            r += str(c) + t[-1]
            t = r
            n -= 1
        return t
