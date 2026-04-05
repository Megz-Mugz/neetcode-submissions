class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        frequency = {}

        for num in nums:
            frequency[num] = 1 + frequency.get(num, 0)

        
        freq_of_nums = []

        for key,value in frequency.items():
            freq_of_nums.append([value, key])

        freq_of_nums = sorted(freq_of_nums, reverse=True)
        freq_of_nums = freq_of_nums[0:k]
        
        return_arr = []

        for arr in freq_of_nums:
            return_arr.append(arr[1])
        
        return return_arr



        