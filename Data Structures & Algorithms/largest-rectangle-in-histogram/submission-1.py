class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        
        max_area = 0
        stack = [] # pair (index, height)

        for index, height in enumerate(heights):
            start = index
            while stack and stack[-1][1] > height:
                # do something
                old_index, old_height = stack.pop()
                max_area = max(old_height * (index - old_index), max_area)
                start = old_index
            
            stack.append((start, height))
        
        for index, height in stack:
            max_area = max(height * (len(heights) - index), max_area)

        return max_area



            