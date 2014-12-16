"""
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
"""


class Solution:
    # @param s, a string
    # @return an integer
    def longestValidParentheses(self, s):
        s = ')' + s
        stack = []
        ans = 0
        for index in xrange(len(s)):
            char = s[index]
            if char == ')' and stack and stack[-1][1] == '(':
                stack.pop()
                ans = max(ans, index - stack[-1][0])
            else:
                stack.append((index, char))
        return ans
