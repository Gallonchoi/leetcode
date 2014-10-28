"""
Find Minimum in Rotated Sorted Array II

->Follow up for "Find Minimum in Rotated Sorted Array":
->What if duplicates are allowed?
->Would this affect the run-time complexity? How and why?

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

The array may contain duplicates.
"""


class Solution:
    # @param num, a list of integer
    # @return an integer
    def findMin(self, num):
        left = 0
        right = len(num)-1
        while left < right:
            mid = left + int((right-left)/2)
            if num[left] < num[right] or right == left:
                return num[left]
            elif num[left] > num[mid]:
                right = mid 
            elif num[left] < num[mid]:
                left = mid+1
            else:
                if num[left] == num[right]:
                    left += 1
                    right -= 1
                else:
                    left = mid + 1
        return num[left]
