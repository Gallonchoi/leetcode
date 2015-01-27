"""
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
"""


class Solution:
    # @param A, a list of integers
    # @return a boolean
    def canJump(self, A):
        i = 0
        reach = 0
        n = len(A)
        while i < n and i <= reach:
            reach = max(i + A[i], reach)
            i += 1
        return True if i == n else False
