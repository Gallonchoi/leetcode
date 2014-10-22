"""
Plus One

Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
"""


class Solution:
    # @param digits, a list of integer digits
    # @return a list of integer digits
    def plusOne(self, digits):
        digits.reverse()
        key = 1
        for i in xrange(len(digits)):
            if digits[i] + key == 10:
                if i == len(digits)-1:
                    digits.append(1)
                digits[i] = 0
            else:
                digits[i] += 1
                break
        digits.reverse()
        return digits
