class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& words) {
        std::unordered_map<std::string, std::vector<std::string>> grouped_words; // sorted_word -> {word, word, word}
        std::vector<std::vector<std::string>> formatted_grouped_words;

        // loop through strs, and sort the word, if the sorted word is NOT in grouped_words, 
        // add the sorted word & the original word itself
        // if the key already exists, simply do grouped_words[sorted_word].push_back(word);

        for (auto& word : words){
            auto original_word = word;
            std::sort(word.begin(), word.end());

            grouped_words[word].push_back(original_word);
        }


        // loop through the values of grouped_words, add those vectors to formatted_grouped_words
        for (const auto& [sorted_word, words] : grouped_words){
            formatted_grouped_words.push_back(words);
        }


        return formatted_grouped_words;
    }
};
