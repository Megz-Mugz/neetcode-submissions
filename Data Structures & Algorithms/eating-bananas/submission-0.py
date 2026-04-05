class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        left = 1
        right = max(piles)
        eating_times = []
        eating_time = 0

        while left <= right:

            mid = (left + right) // 2

            for i in range(len(piles)):
                eating_time += math.ceil(piles[i] / mid)
            print(f'{mid} has an eating time of {eating_time}')


            if eating_time > h:
                left = mid + 1
            else:
                eating_times.append([mid, eating_time])
                right = mid - 1
            eating_time = 0
        print(eating_times)
        return eating_times[-1][0]
