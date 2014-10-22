"""
Swap Nodes in Pairs(https://oj.leetcode.com/problems/swap-nodes-in-pairs/)

Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
"""


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param a ListNode
    # @return a ListNode
    def swapPairs(self, head):
        cursor = ListNode(0)
        cursor.next = head
        former = cursor.next
        latter = former.next if former != None else None
        newHead = former if latter == None else latter
        while former != None and latter != None:
            former.next = latter.next
            latter.next = former
            cursor.next = latter
            cursor = former
            former = cursor.next
            latter = former.next if former != None else None
        return newHead
