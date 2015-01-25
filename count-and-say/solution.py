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
            while t:
                t_len = len(t)
                if len(t) == 1:
                    r += '1' + t
                    break
                for i in range(1, t_len):
                    if t[i] != t[0]:
                        r += str(i) + t[0]
                        t = t[i:]
                        break
                else:
                    r += str(t_len) + t[0]
                    t = t[t_len:]
            t = r
            n -= 1
        return t
