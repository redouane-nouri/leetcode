/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int maxNumberOfBalloons(string text) {
    vector<int> freq(26, 0);

    for (char &c : text)
      ++freq[c - 'a'];

    return min({freq['b' - 'a'], freq[0], freq['l' - 'a'] >> 1,
                freq['o' - 'a'] >> 1, freq['n' - 'a']});
  }
};
