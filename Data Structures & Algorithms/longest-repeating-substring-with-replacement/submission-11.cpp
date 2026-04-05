class Solution {
public:
    int characterReplacement(string s, int k) {
        int longestRepeatingStr = 0;
        std::unordered_map<char, int> frequency;
        int left = 0;
        char mostFreqChar; 

        for (int right = 0; right < s.size(); right++){

            // insert right into frequency
            frequency[s[right]]++;


            // update mostFreq if you found a new letter that occurs 
            // more often than the previously held mostFreq
            if (frequency[s[right]] > frequency[mostFreqChar]){
                mostFreqChar = s[right];
            }

            // check if (use while) the diff sumOfValues - frequency[mostFreqChar] > k, 
            // if it is, start removing left++ from frequency until diff <= k
            while (sumOfValues(frequency) - frequency[mostFreqChar] > k){
                frequency[s[left++]] -= 1;
                // update most freq occuring char
                mostFreqChar = mostFreqOccuringChar(frequency);

            }
            // outside loop, update longestRepeatingStr
            longestRepeatingStr = std::max(sumOfValues(frequency), longestRepeatingStr);
            cout << "Longest repeating str length: " << longestRepeatingStr << " most freq occur char: " << mostFreqChar << endl;
        }
        return longestRepeatingStr;
    }

private: 
    int sumOfValues(const std::unordered_map<char, int>& frequency){
        int runningSum = 0;
        for (const auto& [_, value] : frequency){
            runningSum += value;
        }
        return runningSum;
    }

    char mostFreqOccuringChar(const std::unordered_map<char, int>& frequency){
        char mostSeenChar;
        int occurence{};

        for (const auto& [letter, freq] : frequency){
            if (freq > occurence){
                mostSeenChar = letter;
                occurence = freq;
            }
        }

        return mostSeenChar;
    }
};
