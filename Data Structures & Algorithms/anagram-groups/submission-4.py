class Solution:
    def groupAnagrams(self, words: List[str]) -> List[List[str]]:
        
        seen = {}

        for word in words:
            sorted_word = ''.join(sorted(word))
            if sorted_word in seen:
                seen[sorted_word].append(word)
            else:
                seen[sorted_word] = [word]
        
        output_arr = []

        for key, value in seen.items():
            output_arr.append(value)
        
        return output_arr