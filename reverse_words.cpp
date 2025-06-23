#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

string reverseWords(string s) {
    stringstream ss(s);
    string word;
    vector<string> words;

    // Extract words from the stream
    while (ss >> word) {
        words.push_back(word);
    }

    // Reverse the vector of words
    reverse(words.begin(), words.end());

    // Join the words with a space
    string result;
    for (int i = 0; i < words.size(); i++) {
        result += words[i];
        if (i != words.size() - 1) result += " ";
    }

    return result;
}

int main() {
    string s = "  hello   world  ";
    cout << "Reversed: \"" << reverseWords(s) << "\"" << endl;
    return 0;
}
