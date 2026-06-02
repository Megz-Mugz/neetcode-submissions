class Solution {
public:
    int maxArea(vector<int>& heights) {
        size_t left = 0, right = heights.size() - 1;

        size_t area{};

        while (left < right){
            auto length = right - left;
            auto height = std::min(heights[left], heights[right]);

            area = std::max(area, length * height);

            std::cout << area << std::endl;

            if (heights[left] < heights[right]){
                left++;
            } else {
                right--;
            }
        }

        return area;
    }
};
