using namespace std;

class Solution {
public:

    string encode(vector<string>& strs) {

        string encodedMessage = "";

        for (auto& str : strs){
            encodedMessage += to_string(str.size()) + "#" + str;
        }

        // cout << "Encoded Message: " << encodedMessage << endl;
        return encodedMessage;
    }

    vector<string> decode(string encodedStr) {
        vector<string> originalMessage;

        int currLetter = 0;
        string strNum = "";

        while (currLetter < encodedStr.size()){
            cout << currLetter << ". " << encodedStr[currLetter] << endl;
            if (isdigit(encodedStr[currLetter])){
                strNum += encodedStr[currLetter];
                currLetter++;
            } else {
                currLetter++; // move past delimiter

                cout << "word to add: " << encodedStr.substr(currLetter, stoi(strNum)) << endl;
                originalMessage.push_back(encodedStr.substr(currLetter, stoi(strNum)));
                currLetter += stoi(strNum);
                strNum = "";
            }
        }
        

        // return vector
        return originalMessage;
    }
};