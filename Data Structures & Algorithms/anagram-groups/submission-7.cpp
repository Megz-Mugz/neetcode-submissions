using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& words) {
        unordered_map<string, vector<string>> similar_words; // sorted string -> original string
        vector<vector<string>> result;

        for (int i{}; i < words.size(); i++) {
            string sorted_word = words[i];
            sort(sorted_word.begin(), sorted_word.end());

            similar_words[sorted_word].push_back(words[i]);
        }

        for (const auto& pair : similar_words){
            result.push_back(pair.second);
        }

        return result;
        
    }
};
