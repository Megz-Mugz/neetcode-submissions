class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int left{1}, right{*std::max_element(piles.begin(), piles.end())};
        int k{right};
        int new_rate{};
        int hours_to_eat{};

        while (left <= right){
            new_rate = std::floor((left + right) / 2);
            hours_to_eat = 0;

            std::cout << "left: " << left << " right: " << right << std::endl;
            std::cout << "new rate: " << new_rate << std::endl;
            
            for (auto& pile : piles){
                hours_to_eat += std::ceil(static_cast<double>(pile) / new_rate);
                std::cout << pile << '/' << new_rate << '=' << std::ceil(pile / new_rate) << std::endl;
            }

            std::cout << "hours to eat: " << hours_to_eat << std::endl;

            if (hours_to_eat <= h){
                k = std::min(new_rate, k);
                right = new_rate - 1;
            } else {
                left = new_rate + 1;
            }
        }

        return k;
    }
};
