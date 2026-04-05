class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;
        int maxArea = 0;

        while (left < right){
            
            maxArea = max((min(heights[left], heights[right])) * (right - left), maxArea);

            if (heights[left] < heights[right]){
                left += 1;
            } else {
                right -= 1;
            }
        }

        return maxArea;
    }
};
