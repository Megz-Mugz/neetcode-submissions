class Solution:
    def minWindow(self, s: str, t: str) -> str:

        if len(t) > len(s):
            return ""
        elif s == t:
            return s
        
        # collect indices which have letters in t
        i = 0
        starting_idx = []
        while i < len(s):
            if s[i] in t:
                starting_idx.append(i)
            i += 1
        
        substring = list(t)
        strings = []
        for left in starting_idx:
            substring = list(t)
            right = left
            
            while right < len(s):
                if s[right] in substring:
                    substring.remove(s[right])
                if len(substring) == 0:
                    strings.append(s[left: right + 1])
                right += 1

        # print(sorted(strings, key=len)[0])
        if len(strings) > 0:
            return sorted(strings, key=len)[0]
        else:
            return ""

            

            


