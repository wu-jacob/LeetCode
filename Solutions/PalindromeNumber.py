"""
Given an integer x, return true if x is palindrome integer.

An integer is a palindrome when it reads the same backward as forward.

For example, 121 is a palindrome while 123 is not.
"""

class Solution:
    def isPalindrome(self, x: int) -> bool:
        
        if x < 0:
            return False
        
        divisor = 1
        while x >= 10*divisor:
            divisor = divisor*10
        
        while x:
            first = x // divisor
            last = x % 10

            if first != last:
                return False
            
            x = (x % divisor) // 10
            divisor = divisor / 100
        
        return True
        
        