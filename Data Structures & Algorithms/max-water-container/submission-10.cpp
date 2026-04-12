class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0, right = heights.size() - 1; 
        size_t max_area = 0;

        while (left < right){
            size_t max_height = std::min(heights[left], heights[right]);
            auto length = right - left;

            max_area = std::max(max_area, max_height * length);

            if (heights[left] < heights[right]){
                left++;
            } else {
                right--;
            }

        }

        return max_area;
    }
};
