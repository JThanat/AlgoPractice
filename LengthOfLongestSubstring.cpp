#include <iostream>
#include <unordered_map>

using namespace std;

// Given a string, find the length of the longest substring without repeating characters.
int lengthOfLongestSubstring(string s) {
    unordered_map<char,int> m;
    int ans = 0;
    int k = 0;
    for(int i = 0; i < s.length(); i++) {
        if(m.find(s[i]) != m.end()) {
            // contain key
            if(k < m[s[i]] + 1) k = m[s[i]] + 1; // move tail index to the next of the last found char
            m[s[i]] = i;
        } else {
            // new key
            m[s[i]]++;
        }
        ans = max(ans, i - k + 1);
    }
    return ans;
}