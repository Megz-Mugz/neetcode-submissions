class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        min_heap = []

        for x, y in points:
            distance = math.sqrt((x ** 2) + (y ** 2))
            min_heap.append([distance, x, y])
        
        heapq.heapify(min_heap) # turn array into heap
        
        k_closest_points = []
        while k > 0:
            dist, x, y, = heapq.heappop(min_heap)
            k_closest_points.append([x, y])
            k -= 1
        
        return k_closest_points