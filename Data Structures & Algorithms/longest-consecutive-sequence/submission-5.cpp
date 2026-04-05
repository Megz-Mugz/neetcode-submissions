using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numsSet;
        int longestConsecSequence = 0;
        int consecSequence = 0;
        
        // build hashset
        for (auto& num : nums){
            numsSet.insert(num);
        }

        // {2, 20, 4, 10, 3, 5}

        // loop through each number, and keep 
        // checking to see if currNum + 1 is in the set, update shit accordingly
        for (auto& num : nums){
            int currNum = num;
            while (numsSet.find(currNum) != numsSet.end()){ // O(1) lookup in set
                consecSequence++;
                longestConsecSequence = std::max(consecSequence,longestConsecSequence);
                currNum++;
            }
            consecSequence = 0;
            
        }
        return longestConsecSequence;
    }
};
