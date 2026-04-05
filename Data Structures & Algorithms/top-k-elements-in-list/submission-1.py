class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:

        num_dict = {}
        
        for num in set(nums):
            num_dict[num] = nums.count(num)
        

        # sort the keys from highest to lowest
        sorted_vals = sorted(num_dict.values(), reverse=True)

        returnArr = []
        visited = []

        for occurence in sorted_vals[:k]:
            pos = list(num_dict.values()).index(occurence)
            returnArr.append(list(num_dict.keys())[pos])
            del num_dict[list(num_dict.keys())[pos]]
        return returnArr