#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

string solution(vector<string> A) {
    // Your solution goes here.
    unordered_map<string, int> m;
    string maxBookRoom = "";
    string room;
    maxBookRoom = A[0].substr(1, 2);
    for (string b : A) {
        if (b[0] == '+') {
            room = b.substr(1, 2);
            m[room]++;
            if (m[room] > m[maxBookRoom])
                maxBookRoom = room;
            else if (m[room] == m[maxBookRoom] && room < maxBookRoom)
                maxBookRoom = room;
        }
    }
    return maxBookRoom;
}

int main() {
    vector<vector<string>> A = {
        {"+1A", "+3E", "-1A", "+4F", "+1A", "-3E", "-4F", "+4F", "-4F", "+4F", "-4F", "+4F"}, // 4F
        {"+1A", "-1A", "+3F", "-3F", "+3F", "+8X"}, // 3F
        {"+3F", "-3F", "+3F", "+8X", "+1A", "-1A"}, // 1A
        {"+1A","+3F","+8X","-1A","-3F","-8X"}, // 1A
        {"+0A"}, // 0A
        {"+9Z","−9Z","+9Z","−9Z","+9Z","+3B"} // 9Z
    };
    for (auto a : A) cout << solution(a) << endl;
    return 0;
}