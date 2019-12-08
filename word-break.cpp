#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool> dict;
        for (string s : wordDict) {
            dict[s] = true;
        }
        return wordBreakWithDict(s, dict);
    }

    bool wordBreakWithDict(string s, unordered_map<string, bool> dict) {
        if (s.length() == 0) return true;

        vector<bool> dp(s.length() + 1);
        // dp[i] == true when substr(0,i) can be segmented
        // or str[0,i-1]. In other word, first i character can be segmented...
        for (int i = 1; i <= s.length(); i++) {
            if (dp[i] == false) {
                if (dict[s.substr(0, i)]) dp[i] = true;
            }

            if (dp[i] == true) {
                // check all substr after this
                for (int j = i + 1; j <= s.length(); j++) {
                    if (dp[j] == false && dict[s.substr(i, j - i)]) dp[j] = true;
                    if (j == s.length() && dp[j]) return true;
                }
            }
        }

        return dp[s.length()];
    }
};