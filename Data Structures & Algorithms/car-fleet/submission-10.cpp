class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        std::stack<double> till_finish;
        std::vector<std::pair<int, int>> pos_and_speed;

        // combine position and speed
        for (int i{}; i < position.size(); i++){
            pos_and_speed.push_back({position[i], speed[i]});
        }

        // sort position and speed in descending order
        std::sort(pos_and_speed.begin(), pos_and_speed.end(), 
                [](const pair<int, int>& a, const pair<int, int>& b){
                    return a.first > b.first;
                });
        
        // push to stack only if the current > stack.top()
        for (int i{}; i < pos_and_speed.size(); i++){
            auto [pos, speed] = pos_and_speed[i];
            double time_to_target = static_cast<double> (target - pos) / speed;

            if (till_finish.empty() || time_to_target > till_finish.top()){
                till_finish.push(time_to_target);
            }
        }

        return till_finish.size();
    }
};
