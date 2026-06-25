class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        // better solution? O(log n) -> binary search like solution
        // eating_rate must be between 1 and max number in piles
        // start w/ middle number, and see if we can finish in <= h?
        // if yes, 
            // keep going until you converge
        // if no, increase the eating rate (left = middle + 1)

        int left = 1;
        int right = *std::max_element(piles.begin(), piles.end());

        while (left <= right){
            int eating_rate = left + (right - left) / 2;
            std::cout << "Eating rate: " << eating_rate << std::endl;
            int time = 0;

            for (const auto& pile : piles){
                std::cout << "Adding time: " << std::ceil(pile / eating_rate) << std::endl;
                time += std::ceil(static_cast<double>(pile) / eating_rate);
            }

            std::cout << "Time: " << time << "\n" << std::endl;

            if (time > h){
                // increase eating rate if unable to finish in the allotted time
                left = eating_rate + 1;
            } else {
                // if eating rate suffices, try to minimize the eating rate
                right = eating_rate - 1;
            }
        }

        return left;
    }
};
