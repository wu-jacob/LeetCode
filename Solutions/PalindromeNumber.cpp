class Solution {
public:
    bool isPalindrome(int x) {

        string strx = to_string(x);

        for(int i=0; i<(strx.length()/2); i++)
            if (strx[i] != strx[strx.length()-i-1])
                return false;

        return true;
    }
};
