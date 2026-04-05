class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;
        int maxArea = 0;

        while (left < right){
            
            int width = right - left;
            int height = std::min(heights[left], heights[right]);

            maxArea = std::max(height * width, maxArea);

            if (heights[left] < heights[right]){
                left += 1;
            } else {
                right -= 1;
            }
        }

        return maxArea;
    }
};
