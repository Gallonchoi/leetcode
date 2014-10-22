"""
Maximum depth of binary tree(https://oj.leetcode.com/problems/maximum-depth-of-binary-tree/)

Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
"""

# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param root, a tree node
    # @return an integer
    def maxDepth(self, root):
        lmax = 1
        rmax = 1
        if root == None:
            return 0
        if root.left != None:
            lmax += self.maxDepth(root.left)
        if root.right != None:
            rmax += self.maxDepth(root.right)
        return lmax if lmax > rmax else rmax
