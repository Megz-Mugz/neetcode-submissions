class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        
        s1_as_dict = self.convertToDict(s1)
        print(s1_as_dict)
        left = 0
        right = len(s1) - 1

        while right < len(s2):
            substring = s2[left : right + 1]
            if self.convertToDict(substring) == s1_as_dict:
                return True
            right += 1
            left += 1
        return False

    def convertToDict(self, string: str) -> int:
        collection = {}
        for char in string:
            if char not in collection:
                collection[char] = 1
            else:
                collection[char] += 1
        return collection