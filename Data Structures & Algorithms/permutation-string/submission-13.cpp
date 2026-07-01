class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        /*
        

        

        outside loop return false
        */
        
        std::unordered_map<char, int> s1_map;
        std::unordered_map<char, int> s2_map;
        int left = 0;
        int max_window_size = 0;
    
        // make a mapping of letters to frequency from s1
        for (const auto& letter : s1){
            s1_map[letter]++;
        }
        max_window_size = s1.size();

        // keep looping through s2, adding things into it's map
        for (int right = 0; right < s2.size(); right++){
            s2_map[s2[right]]++;
            
            // if the window becomes to big, remove the leftmost letter & increment left ptr
            while (right - left + 1 > max_window_size){
                s2_map[s2[left]]--;
                if (s2_map[s2[left]] == 0){
                    s2_map.erase(s2[left]);
                }
                left++;
            }

            std::cout << "s1 map" << std::endl;
            for (const auto& [letter, freq] : s1_map){
                std::cout << letter << "-> " << freq << std::endl;
            }

            std::cout << "s2 map" << std::endl;
            for (const auto& [letter, freq] : s2_map){
                std::cout << letter << "-> " << freq << std::endl;
            }

            std::cout << std::endl;
            
            // check if s1's map == s2's map
            if (s1_map == s2_map) return true;
        }

        return false;
    }
};
