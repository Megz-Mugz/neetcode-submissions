class Solution:
    def maxArea(self, heights: List[int]) -> int:
        leftptr = 0
        rightptr = len(heights) - 1
        maxArea = 0
        while(leftptr < rightptr):
            area = (rightptr - leftptr) * min(heights[leftptr], heights[rightptr])
            if(area > maxArea):
                maxArea = area
            if(heights[leftptr] <= heights[rightptr]):
                leftptr+=1
            else:
                rightptr-=1
        return maxArea
