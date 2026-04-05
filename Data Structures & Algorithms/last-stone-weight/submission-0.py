class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        
        # great way to take max heap
        stones = [-s for s in stones]
        heapq.heapify(stones)


        while len(stones) > 1:
            a = -heapq.heappop(stones)  # largest
            b = -heapq.heappop(stones)  # 2nd largest
            if a != b:
                heapq.heappush(stones, -(a - b))  # push negative of the diff

        return -stones[0] if stones else 0