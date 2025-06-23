#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int beautySum(string s) {
    int totalBeauty = 0;

    for (int i = 0; i < s.size(); i++) {
        vector<int> freq(26, 0);  // Frequency of characters in substring

        for (int j = i; j < s.size(); j++) {
            freq[s[j] - 'a']++;

            int maxFreq = INT_MIN, minFreq = INT_MAX;

            for (int k = 0; k < 26; k++) {
                if (freq[k] == 0) continue;
                maxFreq = max(maxFreq, freq[k]);
                minFreq = min(minFreq, freq[k]);
            }

            totalBeauty += (maxFreq - minFreq);
        }
    }

    return totalBeauty;
}

int main() {
    string s = "aabcb";
    cout << "Beauty Sum: " << beautySum(s) << endl;
    return 0;
}
