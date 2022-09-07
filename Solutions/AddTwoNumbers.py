"""
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
"""

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        
        total = 0
        multiplier = 0
        
        while l1 and l2:
            total += ((l1.val + l2.val) * (10 ** multiplier))
            l1 = l1.next
            l2 = l2.next
            multiplier += 1
            print(total)
            print(multiplier)
        
        if l1 or l2:
            while l1:
                total += ((l1.val) * (10 ** multiplier))
                multiplier += 1
                l1 = l1.next
                print(total)
                print(multiplier)

            while l2:
                total += ((l2.val) * (10 ** multiplier))
                multiplier += 1
                l2 = l2.next
                
            multiplier += 1
        
        addition = int(total // (10 ** multiplier))
        while addition == 0 and multiplier > 0:
            multiplier -= 1
            addition = int(total // (10 ** multiplier))
        total = total % (10 ** multiplier)
        new_node = ListNode(addition)
        new_node.next = None
        head = new_node
        multiplier -= 1
        
        while multiplier >= 0:
            addition = total // (10 ** multiplier)
            total = total % (10 ** multiplier)
            new_node = ListNode(addition)
            new_node.next = head
            head = new_node
            multiplier -= 1
            
        return head
        
        