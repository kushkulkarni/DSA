#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string trim(const std::string &str) {
        if (str.empty()) return "";

        size_t start = 0;
        size_t end = str.size() - 1;

        // Find first non-whitespace character
        while (start < str.size() && std::isspace(static_cast<unsigned char>(str[start]))) {
            ++start;
        }

        // Find last non-whitespace character
        while (end > start && std::isspace(static_cast<unsigned char>(str[end]))) {
            --end;
        }

        // Return the trimmed substring
        return str.substr(start, end - start + 1);
    }

    int findWordEnd(int start, string s) {
        int idx = start;
        while(idx < s.length() && s[idx] != ' '){
            idx++;
        }
        return idx - 1;
    }

    string reverseWords(string s) {
        // first reverse whole string
        int idx1 = 0, idx2 = s.length() - 1;
        while(idx1 < idx2){
            swap(s[idx1++], s[idx2--]);
        }

        // Then reverse individual words
        // int i = 0;
        s = trim(s);
        int wordStart = 0;
        int wordEnd = findWordEnd(wordStart, s);
        while(wordStart < s.length() && wordEnd < s.length()){
            wordEnd = findWordEnd(wordStart, s);
            if(s[wordStart] == ' '){
                wordStart++;
             continue;
            }
            int end = wordEnd;
            while(wordStart < wordEnd) {
                // cout << "start: " << wordStart << " end: " << wordEnd << endl;
                swap(s[wordStart++], s[wordEnd--]);
            }
            wordStart = end+2;
        }
        int idx = 0;
        while(idx < s.length()){
             if(s[idx] == ' ' && idx + 1 < s.length() && s[idx+1] == ' ') {
                cout << "REMOVING EXTRA SPACE FOUND at idx: "<< idx+1 << endl;
                s.erase(idx+1, 1);
                continue;
            }
                idx++;
        }
        return s;
    }
};

int main() {
    Solution obj;
    string s = obj.reverseWords(" 3c      2zPeO dpIMVv2SG    1AM       o       VnUhxK a5YKNyuG     x9    EQ  ruJO       0Dtb8qG91w 1rT3zH F0m n G wU");
    cout << s;
 return 1;   
}