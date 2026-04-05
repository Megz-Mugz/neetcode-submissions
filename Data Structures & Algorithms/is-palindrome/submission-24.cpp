class Solution {
public:
    bool isPalindrome(string s) {
        int left, right;
        left = 0; 
        right = s.size() - 1;

        while (left < right){
            std::cout << s[left] << std::endl;
            std::cout << s[right] << std::endl;
            
            while (left < right && !std::isalnum(s[left])) left++;

            while (left < right && !std::isalnum(s[right])) right--;

            if (std::tolower(static_cast<unsigned char>(s[left])) != 
                std::tolower(static_cast<unsigned char>(s[right]))) return false;

            left++;
            right--;
        }

        return true;
    }
};
