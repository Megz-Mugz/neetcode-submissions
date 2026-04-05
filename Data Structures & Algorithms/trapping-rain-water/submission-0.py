class Solution:
    def trap(self, heights: List[int]) -> int:
        left, right = 0, len(heights) - 1
        max_left, max_right = heights[left], heights[right]

        output = 0
        while left < right:

            if max_left <= max_right:
                # work with left ptr
                height = heights[left]
                output += max_left - height if max_left - height >= 0 else 0
                max_left = max(max_left, height)
            else:
                # work with right ptr
                height = heights[right]
                output += max_right - height if max_right - height >= 0 else 0
                max_right = max(max_right, height)
            
            if heights[left] <= heights[right]:
                left += 1
            else:
                right -= 1
        
        return output

        
