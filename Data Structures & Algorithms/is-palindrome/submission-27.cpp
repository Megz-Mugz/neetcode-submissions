class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        
        // 2 pointer condition
        while (left < right){
            
            // only compare alpha-numeric characters
            while (left < right && !std::isalnum(s[left])){ left++; }
            while (left < right && !std::isalnum(s[right])){ right--; }

            // compare the two letters
            if (std::tolower(s[left]) != std::tolower(s[right])) return false;

            // move pointers
            left++;
            right--;

        }

        // indcates the string was a palindrome
        return true;

    }
};
