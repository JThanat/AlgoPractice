/**
 * Source: https://leetcode.com/discuss/interview-question/356477
 **/
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    string keyboards = "abcdefghijklmnopqrstuvwxy";
    string text = "cba";
    unordered_map<char, int> keyMap;

    for (int i = 0; i < keyboards.length(); i++) {
        keyMap[keyboards[i]] = i;
    }

    int lastTypeIdx = 0;
    int move = 0;
    for (int i = 0; i < text.length(); i++) {
        move += abs(lastTypeIdx - keyMap[text[i]]);
        lastTypeIdx = keyMap[text[i]];
    }
    cout << move;

    return 0;
}