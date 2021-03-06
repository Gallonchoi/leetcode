"""
Find Minimum in Rotated Sorted Array

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
"""


class Solution:
    # @param num, a list of integer
    # @return an integer
    def findMin(self, num):
        left = 0
        right = len(num)-1
        mini = 0
        while right >= left:
            mid = left + int((right-left)/2)
            if num[left] <= num[right]:
                mini = num[left]
                break
            elif num[left] <= num[mid]:
                left = mid+1
            else:
                right = mid
        return mini
