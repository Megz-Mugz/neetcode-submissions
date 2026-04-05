class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int N = temperatures.size();

        std::vector<int> results(N, 0);

        std::stack<std::pair<int, int>> temp_stack;

        for (int i = 0; i < N; i++){

            while ((!temp_stack.empty()) && temperatures[i] > temp_stack.top().first){
                auto [_, popped_index] = temp_stack.top(); 
                temp_stack.pop();
                results[popped_index] = i - popped_index;
            }

            temp_stack.push({temperatures[i], i});
        }


        return results;
    }
};
