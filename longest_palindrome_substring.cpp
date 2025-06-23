#include <iostream>
using namespace std;

class Solution {
public:
    void expand(int i, int j, const string& s, int& start, int& maxlen) {
        while (i >= 0 && j < s.size() && s[i] == s[j]) {
            if (j - i + 1 > maxlen) {
                start = i;
                maxlen = j - i + 1;
            }
            i--;
            j++;
        }
    }

    string longestPalindrome(string s) {
        if (s.empty()) return "";

        int start = 0, maxlen = 1;
        for (int i = 0; i < s.size(); i++) {
            expand(i, i, s, start, maxlen);       // Odd length
            expand(i, i + 1, s, start, maxlen);   // Even length
        }

        return s.substr(start, maxlen);
    }
};

int main() {
    Solution a;
    string s = "ageggaagagagagaggagaagaghwhfebbjrbrebbebrhvfhverhvbfc";
    string b = a.longestPalindrome(s);
    cout << "Longest Palindromic Substring: " << b << endl;
    return 0;
}
