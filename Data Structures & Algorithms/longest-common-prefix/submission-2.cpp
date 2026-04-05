class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        // go thru the list of strings (while loop)
            // keep track of the looping condition & which letter you are checking
        // if it's the first word, make that letter a "contender"
        // if every other string's ith index matches the contender, by the time you reach the last 
        // string, add it to the longest_common_prefix,
        // otherwise, break and return longest_common_prefix
        std::string longest_common_prefix = "";
        bool keep_searching = true;
        int letter_idx = 0;
        char contender;
        int N = strs.size();

        while (keep_searching){

            for (int word_idx = 0; word_idx < N; word_idx++){
                // guard rail - if the letter_idx is bigger than the size of the word, break 
                if (letter_idx >= strs[word_idx].size()) {
                    keep_searching = false;
                    break;
                }

                // if it's the first word, make it the contender
                if (word_idx == 0){
                    contender = strs[word_idx][letter_idx];
                // for every other word, check to see the current letter is not equal to contender
                } else if (strs[word_idx][letter_idx] != contender){
                    keep_searching = false;
                    break;
                }
                
                // last letter
                if (word_idx == N - 1){
                    // already checked if it's a contender above
                    longest_common_prefix += strs[word_idx][letter_idx++]; // move to next letter
                }
            }
        }

        return longest_common_prefix;
    }
};