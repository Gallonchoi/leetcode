"""
Maximum Product Subarray

Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
"""


class Solution:
    # @param A, a list of integers
    # @return an integer
    def maxProduct(self, A):
        min_temp = A[0]
        max_temp = A[0]
        max_ans = A[0]
        for i in xrange(1, len(A)):
            temp = [A[i], A[i] * max_temp, A[i] * min_temp]
            max_temp, min_temp = max(temp), min(temp)
            max_ans = max(max_ans, max_temp)
        return max_ans
