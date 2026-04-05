class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        left, right = 1, max(piles)


        while left <= right:

            middle_num = (left + right) // 2
            time = 0

            for pile in piles:
                time += math.ceil(pile / middle_num)

            if time > h:
                left = middle_num + 1
            else:
                right = middle_num - 1
                
        
            print(f'left: {left} right: {right}')
        return left