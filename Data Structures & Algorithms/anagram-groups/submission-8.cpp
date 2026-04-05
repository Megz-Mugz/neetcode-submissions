class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // put each word into unordered map w/ sorted_word -> {word} 
        std::unordered_map<std::string, std::vector<std::string>> mappings;

        for (auto& str : strs){
            std::string original_word = str;
            // sort the word & use it in mappings look up
            std::sort(str.begin(), str.end());
            auto it = mappings.find(str);

            if (it != mappings.end()){
                mappings[str].push_back(original_word); 
            } else {
                mappings[str] = {original_word};
            }
        }

        std::vector<std::vector<std::string>> result;

        for (auto& [key, val] : mappings){
            result.push_back(std::move(val));
        }

        return result;
    }
};
