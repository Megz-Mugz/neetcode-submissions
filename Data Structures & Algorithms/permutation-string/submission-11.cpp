class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.size() < s1.size()) return false;
        
        std::unordered_map<char, int> s1_map;
        int k = s1.size();

        for (auto& letter : s1){
            s1_map[letter]++;
        }
        
        int left = 0;
        int right = 0;
        std::unordered_map<char, int> s2_map; // e -> 1, c -> 1, a-> 1

        while (right < s2.size()){
            
            // keep adding to the map
            s2_map[s2[right]]++;

            // if the window (inclusive of right) gets too big, adjust it
            if (right - left + 1 > k) {
                s2_map[s2[left]]--;
                if (s2_map[s2[left]] == 0) s2_map.erase(s2[left]);
                left++;
            }

            if (s1_map == s2_map) return true;
            right++;
        }

        // outside the loop return false
        return false;
    }

};
