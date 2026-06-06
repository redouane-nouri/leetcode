/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
    ll memoCnt[16][10][10];
    ll memoSum[16][10][10];
    string digitStr;
    int numDigits;

    pair<ll, ll> dfs(int pos, int prev, int curr, bool isLimit, bool isLeading) {
        if (pos == numDigits)
            return {1, 0};

        if (!isLimit && !isLeading && prev >= 0 && curr >= 0)
            if (memoCnt[pos][prev][curr] != -1)
                return {memoCnt[pos][prev][curr], memoSum[pos][prev][curr]};

        ll cnt = 0, sum = 0;
        int upperBound = isLimit ? digitStr[pos] - '0' : 9;

        for (int digit = 0; digit <= upperBound; ++digit) {
            bool newIsLeading = isLeading && (digit == 0);
            int newPrev = curr,
                newCurr = newIsLeading ? -1 : digit;

            auto [subCnt, subSum] = dfs(
                pos + 1,
                newPrev,
                newCurr,
                isLimit && (digit == upperBound),
                newIsLeading
            );

            if (!newIsLeading && prev >= 0 && curr >= 0)
                if ((prev < curr && curr > digit) || (prev > curr && curr < digit))
                    sum += subCnt;

            cnt += subCnt;
            sum += subSum;
        }

        if (!isLimit && !isLeading && prev >= 0 && curr >= 0)
            memoCnt[pos][prev][curr] = cnt,
            memoSum[pos][prev][curr] = sum;

        return {cnt, sum};
    }

public: 
    ll solve(ll num) {
        if (num <= 100)
            return 0;

        digitStr = to_string(num);
        numDigits = digitStr.size();

        memset(memoCnt, -1, sizeof(memoCnt));
        memset(memoSum, -1, sizeof(memoSum));

        auto [_, totalSum] = dfs(0, -1, -1, true, true);
        return totalSum;
    }

    ll totalWaviness(ll num1, ll num2) {
        return solve(num2) - solve(num1 - 1);
    }
};
