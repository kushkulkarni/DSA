#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0, end = s.length() - 1;

        while(start < end){
            if(!isalnum(s[start])){
                start++;
                continue;
            }
            if(!isalnum(s[end])){
                end--;
                continue;
            }
            if(!isdigit(s[start]) && !isdigit(s[end]) && tolower(s[start]) != tolower(s[end])){
              return false;
            }
            if((isdigit(s[start]) || isdigit(s[end])) && s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};