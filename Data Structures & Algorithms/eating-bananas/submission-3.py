class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        
        left, right = 1, max(piles)

        least_time = right

        while left <= right:

            bananas_per_hour = (left + right) // 2

            total_time = 0
            for pile in piles:
                total_time += math.ceil(pile / bananas_per_hour)

            if total_time <= h:
                least_time = min(bananas_per_hour, least_time)
                right = bananas_per_hour - 1
            else:
                left = bananas_per_hour + 1
        
        return least_time


