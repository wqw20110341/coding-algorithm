//
// Created by 12582 on 2025/1/10.
//

#include <bits/stdc++.h>
#include <iostream>
#include <climits>
#include <utility>
#include <algorithm>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <map>
#include <vector>
#include <array>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <unordered_set>
#include <bitset>
#include <cassert>
#include <random>
#include <sstream>
#include <iomanip>
#include <functional>
#include <chrono>

using namespace std;

class Solution {
private:
    bool ok(int *cnt1, int *cnt2) {
        for (int i = 0; i < 26; i++) {
            if (cnt1[i] < cnt2[i]) {
                return false;
            }
        }
        return true;
    }

public:
    long long validSubstringCount(string word1, string word2) {

        int cnt1[26] = {0}, cnt2[26] = {0};

        for (char c: word2) {
            cnt2[c - 'a']++;
        }

        long long ans = 0;

        for (int l = 0, r = 0; l < word1.size(); l++, r = max(r, l)) {
            if (l) {
                cnt1[word1[l - 1] - 'a']--;
            }

            while (!ok(cnt1, cnt2)) {

                if (r == word1.size()) {
                    return ans;
                }

                cnt1[word1[r++] - 'a']++;
            }
            ans += word1.size() - r + 1;
        }

        return ans;
    }

};


int main() {
    Solution sol;
    cout << sol.validSubstringCount("bcca", "abc") << endl;
    cout << sol.validSubstringCount("abab", "abc") << endl;
    cout << sol.validSubstringCount("aaaa", "aa") << endl;
    cout << sol.validSubstringCount("aaaaa", "aa") << endl;
    cout << sol.validSubstringCount("a", "aa") << endl;
    cout << sol.validSubstringCount("a", "a") << endl;
    cout << sol.validSubstringCount("abcde", "ace") << endl;
    cout << sol.validSubstringCount("abcde", "abc") << endl;

    return 0;
}
