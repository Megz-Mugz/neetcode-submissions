class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right){
            while (!isalnum(s[left])){
                left += 1;
            }

            while (!isalnum(s[right])){
                right -= 1;
            }

            if (left < right && tolower(s[left]) != tolower(s[right])) {
                cout << "Left: " << s[left] << " Right: " << s[right] << endl;
                return false;
            }

            left += 1;
            right -= 1;

        }

        return true;
        
    }
};
