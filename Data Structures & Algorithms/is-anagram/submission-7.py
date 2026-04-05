class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        print(Counter(s))
        if (len(s) != len(t)):
            return False
        
        all_letters_in_s = list(s)
        all_letters_in_t = list(t)
    
        s_letters = set(all_letters_in_s)
        t_letters = set(all_letters_in_t)

        if s_letters != t_letters:
            return False


        for letter in s_letters:
            if (all_letters_in_s.count(letter) != all_letters_in_t.count(letter)):
                return False
        
        return True




        