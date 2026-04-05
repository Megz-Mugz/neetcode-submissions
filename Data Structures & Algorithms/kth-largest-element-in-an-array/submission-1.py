class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        
        # generate min heap & apply -1 transformation to force numbers into min heap
        # do this to get the largest values at the top
        arr = [num * -1 for num in nums]
        heapq.heapify(arr)
        
        # keep popping values until you reach just before the end
        while k > 1:
            heapq.heappop(arr)
            k -= 1

        # handled duplicates, pop the next min value, and re-apply -1 transformation to get original value
        return heapq.heappop(arr) * -1 