class Solution {
public:
    int lengthOfLastWord(string s) {

        int stringLength = 0;
        
        for (int i = s.length() -1; i >= 0; i -= 1) {
            if (isspace(s[i])) {
                cout << "space" << endl;
                if (stringLength > 0) {
                    return stringLength; }
            }
            else { cout << s[i]; stringLength++; }
        }

        return stringLength;
    }
};
