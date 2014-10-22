"""
Single Number (https://oj.leetcode.com/problems/single-number/)

Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
"""


class Solution:
    # @param A, a list of integer
    # @return an integer
    def singleNumber(self, A):
        for i in xrange(1, len(A)):
            A[i] ^= A[i-1]
        return A[len(A)-1]
