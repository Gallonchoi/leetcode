"""
Given a string, find the length of the longest substring without repeating characters.
For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.
For "bbbbb" the longest substring is "b", with the length of 1.

"""
class Solution:
    # @return an integer
    def lengthOfLongestSubstring(self, s):
        mark = {}
        left = right = 0
        max_len = 0
        s_len = len(s)
        while right < s_len:
            if mark.get(s[right], -1) >= left:
                left = mark[s[right]] + 1
            mark[s[right]] = right
            right += 1
            max_len = max(max_len, right - left)
        return max_len
