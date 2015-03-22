"""
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
"""


class Solution:
    # @return a boolean
    def isValid(self, s):
        st = []
        bracket = {'(': ')',
                   '[': ']',
                   '{': '}'}
        for i in s:
            if i in bracket.keys():
                st.append(i)
            elif len(st) == 0 or bracket[st.pop()] != i:
                return False
        return True if len(st) == 0 else False
