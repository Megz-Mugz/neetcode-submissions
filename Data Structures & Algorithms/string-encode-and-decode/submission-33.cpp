class Solution {
public:

    string encode(vector<string>& strs) {
        std::string encoded_str;

        for(const auto& str : strs){
            encoded_str += std::format("{}%{}", str.size(), str);
        }

        std::cout << encoded_str << std::endl;
        return encoded_str; // 5%Hello11%RohanMengle
    }

    vector<string> decode(string s) {
        std::vector<std::string> decoded_strs;
        const char DELIMITER = '%';
        int cur_idx = 0;

        while (cur_idx < s.size()){
            std::string chars_to_read = "";
            std::string curr_word = "";
            
            // find how many characters to read for current word
            while (s[cur_idx] != DELIMITER){
                chars_to_read += s[cur_idx++];
            }
            
            // skip past delimiter
            cur_idx++; 

            // convert to a number
            int _chars_to_read = std::stoi(chars_to_read);

            // read this many chars in string, and build word
            while (_chars_to_read > 0){
                curr_word += s[cur_idx++];
                _chars_to_read--;
            }

            // add word to the result vector
            std::cout << curr_word << std::endl;
            decoded_strs.push_back(curr_word);
        }

        return decoded_strs;
    }
};
