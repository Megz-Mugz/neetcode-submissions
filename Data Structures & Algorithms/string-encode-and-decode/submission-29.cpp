class Solution {
public:

    string encode(vector<string>& strs) {
        std::string encoded_str = "";

        for (auto& str : strs){
            encoded_str += std::to_string(str.size()) + "#" + str;
        }

        std::cout << encoded_str << std::endl;
        return encoded_str;
    }

    vector<string> decode(string encoded_str) {
        std::vector<string> decoded_strs;
        std::string num_str;
        int chars_to_read{};
        int i{};
        std::string curr_word;

        while (i < encoded_str.size()){

            while (encoded_str[i] != '#'){
                num_str += encoded_str[i++];
            }
            
            i += 1; // move past #
            chars_to_read = std::stoi(num_str);
            
            while (chars_to_read > 0){
                curr_word += encoded_str[i++];
                chars_to_read--;
            }
            
            decoded_strs.push_back(curr_word); // push word into res array

            // reset stuff
            chars_to_read = 0;
            num_str = "";
            curr_word = "";
        }

        return decoded_strs;
    }
};
