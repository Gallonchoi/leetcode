"""
Sort List

Sort a linked list in O(n log n) time using constant space complexity.
"""


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param head, a ListNode
    # @return a ListNode
    def sortList(self, head):
        num = []
        elem = head
        while elem != None:
            num.append(elem.val)
            elem = elem.next
        num.sort()
        elem = head
        i = 0
        while elem != None:
            elem.val = num[i]
            i += 1
            elem = elem.next
        return head
