class Solution:
    def isPalindrome(self, s: str) -> bool:
        t = "".join(char for char in s if char.isalnum())

        l, r = 0, len(t) - 1
        while l < r:
            if t[l].lower() == t[r].lower():
                l += 1
                r -= 1
            else: 
                return False
        return True