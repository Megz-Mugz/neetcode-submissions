class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        
        arr = []
        for num in nums:
            arr.append(num * -1)

        heapq.heapify(arr)
        
        while k > 1:
            heapq.heappop(arr)
            k -= 1

        return heapq.heappop(arr) * -1