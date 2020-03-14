/**
 * Source: https://leetcode.com/discuss/interview-question/356520
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> S = {1, 2, 6, 5, 3};
    vector<int> E = {5, 5, 7, 6, 8};
    sort(S.begin(), S.end()); // 1 2 3 5 6
    sort(E.begin(), E.end()); // 5 5 6 7 8 
    int i = 0, j = 0;
    int n = S.size();
    int maxCount = 0;
    int curCount = 0;

    while(i < n && j < n) {
        if(S[i] < E[j]) {
            curCount++;
            i++;
            maxCount = max(maxCount,curCount);
        } else {
            curCount--; // never go to negative since there must be n guest come before n guest can leave
            j++;
        }
    }
    cout << maxCount;
    return 0;
}