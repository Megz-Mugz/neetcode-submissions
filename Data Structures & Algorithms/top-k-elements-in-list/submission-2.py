class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        
        numbers_freq = {} # [number : frequency]

        for num in nums:
            numbers_freq[num] = 1 + numbers_freq.get(num, 0)

        # with frequency on the inside, invert hashmap
        freq_numbers = []
        for key, value in numbers_freq.items():
            freq_numbers.append([value, key])
        
        freq_numbers.sort(reverse=True)
        
        return_nums = []

        for i in range(0, k):
            return_nums.append(freq_numbers[i][1])
        
        print(return_nums)
        return return_nums