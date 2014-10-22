"""
Remove Duplicates from Sorted List(https://oj.leetcode.com/problems/remove-duplicates-from-sorted-list/)

Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
"""


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param head, a ListNode
    # @return a ListNode
    def deleteDuplicates(self, head):
        cur = head
        tmp = head.next if head != None else None
        while tmp != None:
            if cur.val == tmp.val:
                cur.next = tmp.next
            else:
                cur = cur.next
            tmp = tmp.next
        return head
