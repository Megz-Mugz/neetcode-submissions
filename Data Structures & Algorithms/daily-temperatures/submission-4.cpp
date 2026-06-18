class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::vector<int> warmer_temp_appears(temperatures.size(), 0);

        std::stack<std::pair<int, int>> temp_and_index;

        // less than or equal to top of stack, push on stack

        // while the curr number is > top of stack, pop it and update the index in warmer_temp_appears

        for (int i{0}; i < temperatures.size(); i++){
            int curr_temp = temperatures[i];

            while(!temp_and_index.empty() && curr_temp > temp_and_index.top().first){
                int temp = temp_and_index.top().first;
                int index = temp_and_index.top().second;

                warmer_temp_appears[index] = i - index;

                // remove from stack
                temp_and_index.pop();
            }
            temp_and_index.push({curr_temp, i});
        }
        return warmer_temp_appears;
    }
};