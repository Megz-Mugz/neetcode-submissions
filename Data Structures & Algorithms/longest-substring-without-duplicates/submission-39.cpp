class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        /*
        set = z, x, y
        
        zxyzxyz

        while curr_idx < s.size()

        on index 3, z is found to be a duplicate, 
            determine if this is the new longest substring
            i = 0
            while i < curr_idx, keep popping from set until you don't have duplicate
        no duplicate
            add letter at curr_idx to set
        */
        int longest_sub_str = 0;
        int curr_idx = 0;
        int i = 0;
        std::set<int> letters;

        while (curr_idx < s.size()){
            
            while (letters.contains(s[curr_idx])){
                // determine if current substring is the new longest substring
                longest_sub_str = std::max(longest_sub_str, static_cast<int>(letters.size()));

                if (i < curr_idx){
                    letters.erase(s[i]);
                    i++;
                }
            } 
            letters.insert(s[curr_idx]);
            curr_idx++;
        }

        return std::max(longest_sub_str, static_cast<int>(letters.size()));
    }
};