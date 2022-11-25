class Solution {
public:
    int romanToInt(string s) {
        map<char,int> romans = {
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };
        
        int i = 0;
        int total = 0;

        if (s.length() <= 1)
            return romans[s[0]];

        while (i<s.length()) {

            int first = romans[s[i]];
            int second = romans[s[i+1]];

            if (first >= second) {
                total += first;
                i++;
            }

            if (first < second) {
                total += (second - first);
                i += 2;
            }
        }

        return total;

    }
};
