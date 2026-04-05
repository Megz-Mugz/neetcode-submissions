class Solution {
public:
    // ["#hello"] -> 11##hellohello in decode, only start AFTER first #
    string encode(vector<string>& strs) {
        std::string encoded_str = "";
        for (const auto& str : strs){
            encoded_str += std::to_string(str.size()) + '#' + str;
        }

        std::cout << encoded_str << std::endl;
        return encoded_str;
    }

    // 5Hello5World
    vector<string> decode(string s) {
        std::vector<std::string> original_text;
        /*
            1. keep collecting numbers in word_len
            2. once you see a '#' stop collecting numbers
            3. do stoi(word_len)
            4. run another loop for the len of word_len 
                5. append each character to a temp str
            6. push end of that loop, push to original_text vec
            7. repeat
        */
        int cursor{0};
        const size_t S_SIZE = s.size();
        const char DELIMITER = '#';
        // // 11##hellohello
        while (cursor < S_SIZE){
            std::string word_len = "";
            std::string curr_word = "";
            
            // collect the length of the word
            while (cursor < S_SIZE && s[cursor] != DELIMITER){
                word_len += s[cursor++];
            }
            
            auto word_len_num = std::stoi(word_len);
            std::cout << word_len << std::endl;
            cursor++; // move past delimiter

            // build out current word
            while (word_len_num){
                curr_word += s[cursor++];
                --word_len_num;
            }

            std::cout << curr_word << std::endl;
            original_text.push_back(curr_word);
        }

        return original_text;
    }
};
