# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def gcd(self, a, b):
        if a < b:
            a, b = b, a
        
        while b:
            remain = a % b
            a = b
            b = remain

        return a

    def insertGreatestCommonDivisors(self, head: Optional[ListNode]) -> Optional[ListNode]:
        first = head
        second = first.next

        while second:
            gcd = self.gcd(first.val, second.val)

            newGcd = ListNode(gcd, second)
            first.next = newGcd

            first = second
            second = first.next

        return head
