"""
Reverse Words in a String

Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

click to show clarification.

Clarification:
What constitutes a word?
A sequence of non-space characters constitutes a word.
Could the input string contain leading or trailing spaces?
Yes. However, your reversed string should not contain leading or trailing spaces.
How about multiple spaces between two words?
Reduce them to a single space in the reversed string.
"""


class Solution:
    # @param s, a string
    # @return a string
    def reverseWords(self, s):
        character = s.split(' ')
        for i in xrange(character.count('')):
            character.remove('')
        character.reverse()
        new_word = ' '.join(character)
        return new_word
