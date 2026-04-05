class Solution {
public:
    string encode(vector<string>& strs) {
        
        // encode the string using a # as delimiter
        std::string encoded_str = "";
        for (const auto& str : strs){
            encoded_str += std::to_string(str.size()) + '#' + str;
        }

        std::cout << encoded_str << std::endl;
        return encoded_str;
    }

    vector<string> decode(const string& s) {
        
        std::vector<std::string> original_text;
        int cursor{0};
        const size_t S_SIZE = s.size();
        const char DELIMITER = '#';

        while (cursor < S_SIZE){
            
            // reset for each new word
            std::string word_len_str = "";
            std::string curr_word = "";
            
            // collect the length of the word
            while (s[cursor] != DELIMITER){
                word_len_str += s[cursor++];
            }
            
            // convert word length to a string, makes it easier to iterate on
            auto word_len_num = std::stoi(word_len_str);
            std::cout << word_len_num << std::endl;

            // move past delimiter
            cursor++; 

            // build out current word
            while (word_len_num){
                curr_word += s[cursor++];
                word_len_num--;
            }

            // add the collected word to the result's vector
            std::cout << curr_word << std::endl;
            original_text.push_back(curr_word);
        }

        return original_text;
    }
};
