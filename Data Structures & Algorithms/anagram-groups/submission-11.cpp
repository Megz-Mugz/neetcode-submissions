class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& words) {
        
        // sorted_word -> {word, word, word}
        std::unordered_map<std::string, std::vector<std::string>> grouped_words; 
        std::vector<std::vector<std::string>> formatted_grouped_words;

        for (const auto& original_word : words){
            auto sorted_word = original_word;    
            std::sort(sorted_word.begin(), sorted_word.end());
            grouped_words[sorted_word].push_back(original_word);
        }

        for (const auto& [_, words] : grouped_words){
            formatted_grouped_words.push_back(words);
        }

        return formatted_grouped_words;
    }
};
