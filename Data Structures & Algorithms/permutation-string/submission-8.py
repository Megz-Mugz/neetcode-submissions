class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        
        
        left, right = 0, len(s1) - 1 # ONLY width of window 
        s1_counter = dict(Counter(s1))
        while right < len(s2):
            if s1_counter == dict(Counter(s2[left : right + 1])):
                return True
            left += 1
            right += 1
        return False