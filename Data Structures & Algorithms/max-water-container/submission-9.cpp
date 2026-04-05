class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;
        int calc_area = 0;
        int max_area = 0;

        while (left < right){
            calc_area = (right - left) * std::min(heights[left], heights[right]);
            max_area = std::max(max_area, calc_area);

            if (heights[right] >= heights[left]){
                left++;
            } else {
                right--;
            }
        }

        return max_area;
    }
};
