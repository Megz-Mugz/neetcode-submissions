class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        
        s_dict, t_dict = {}, {}

        
        for letter_s in s:
            s_dict[letter_s] = 1 + s_dict.get(letter_s, 0)
        for letter_t in t:
            t_dict[letter_t] = 1 + t_dict.get(letter_t, 0)

        
        return s_dict == t_dict