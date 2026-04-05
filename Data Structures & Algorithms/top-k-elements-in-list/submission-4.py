class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        
        freq = Counter(nums)
        sorted_by_freq = sorted(nums, key=lambda num : -freq[num])

        output = []
        index = 0
        while len(output) < k:
            if sorted_by_freq[index] not in output:
                output.append(sorted_by_freq[index])
            index += 1
        return output