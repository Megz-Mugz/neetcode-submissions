class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        
        # { aht => [hat]
        #   act => [act, cat]
        #   stop => [stop, pots, tops]}
        seen = {}

        for word in strs:
            sorted_word = ''.join(sorted(word))

            if sorted_word in list(seen.keys()):
                seen[sorted_word].append(word)
            else:
                seen[sorted_word] = [word]
        
        return list(seen.values())
            