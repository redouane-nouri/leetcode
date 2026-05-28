/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lw(26, -1), fu(26, -1);

        for (int i = 0; i < word.size(); ++i) {
            char c = word[i];
            if (islower(c))
                lw[c - 'a'] = i;
            else if (fu[c - 'A'] == -1)
                fu[c - 'A'] = i;
        }

        int ans = 0;
        for (int i = 0; i < 26; ++i)
            if (lw[i] != -1 && lw[i] < fu[i])
                ++ans;

        return ans;
    }
};
