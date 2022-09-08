"""
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
"""

class Solution:
    def isValid(self, s: str) -> bool:
        
        dictionary = {"(":")", "[":"]", "{":"}"}
        
        if len(s) == 0:
            return True
        
        if len(s) == 1:
            return False
        
        stack = [] 
        for c in s:
            if c not in dictionary:
                if len(stack) == 0:
                    return False
                if dictionary[stack[-1]] == c:
                    stack.pop()
                else: 
                    return False
            else:
                stack.append(c)
        
        if len(stack) == 0:
            return True
        else:
            return False
            
        