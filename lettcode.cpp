//
// Created by NUC on 2023/3/28.
//

# include <iostream>
#include  <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        int temp = 0;
        for (char *c = (char *)s.c_str(); *(c); c++){
            temp = getValue(*(c));
            if (!*(c+1)) break;
            if (temp >= getValue(*(c+1))) {
                res += temp;
            }else{
                res -= temp;
            }
        }
        res += temp;

        return res;
    }


    int getValue(char ch) {
        switch(ch) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }
};


int main() {
    Solution s = Solution();
    cout << s.romanToInt("III");

    return 0;
}

/*
class Solution {
    public:
    int romanToInt(string s) {
        int res = 0;
        for (int i = 0; i < s.length() - 1; i++){
            if (getValue(s[i]) >= getValue(s[i+1])) {
                res += getValue(s[i]);
            }else{
                res -= getValue(s[i]);

            }
        }
        res += getValue(s[s.length()-1]);
        return res;
    }
    int getValue(char ch) {
        switch(ch) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }

};
*/