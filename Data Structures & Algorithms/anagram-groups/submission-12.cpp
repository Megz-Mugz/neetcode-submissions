class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> grouped_words; // sorted_word -> [word, word]
        std::vector<std::vector<std::string>> formatted_words;

        for (const auto& word : strs){
            auto sorted_word = word;
            std::sort(sorted_word.begin(), sorted_word.end());

            grouped_words[sorted_word].push_back(word);
            
        }

        for (const auto& [sorted_word, words] : grouped_words){
            formatted_words.push_back(words);
        }


        return formatted_words;


    }
};
