class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        std::vector<std::tuple<int, int, double>> position_speed_time;
        std::stack<double> times;
        constexpr int TIME = 2;
        constexpr size_t FIRST_VEHICLE = 0;
        
        // store position, speed, and time (target - position) / speed into one structure
        for (int i{}; i < position.size(); i++){
            position_speed_time.push_back(
                std::tuple(
                    position[i], 
                    speed[i], 
                    static_cast<double>(target - position[i]) / speed[i]
                ));

        }
        
        // sort in descending order by position
        std::sort(position_speed_time.begin(), position_speed_time.end(), std::greater<>());

        // vehicle that's furthest ahead, so we have a baseline to compare other values against
        times.push(std::get<TIME>(position_speed_time[FIRST_VEHICLE]));

        for (int i{1}; i < position_speed_time.size(); i++){
            if (!times.empty() && std::get<TIME>(position_speed_time[i]) > times.top()){
                times.push(std::get<TIME>(position_speed_time[i]));
            } 
        }

        return times.size();
    }
};
