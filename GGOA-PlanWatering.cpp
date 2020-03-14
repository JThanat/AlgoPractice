/**
 * Source: https://leetcode.com/discuss/interview-question/394347/
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> flowers = {2,4,5,1,2}; 
    int cap1 = 5, cap2 = 7;
    int l = 0, r = flowers.size()-1;

    int curL = 0;
    int curR = 0;
    int countL = 0;
    int countR = 0;
    while(l <= r) {
        if(l == r) {
            if(flowers[l] > curL + curR) {
                countL++;
            }
        } else {
            if(curL < flowers[l]) {
                countL++;
                curL = cap1 - flowers[l];
            } else {
                curL -= flowers[l];
            }
            if(curR < flowers[r]) {
                countR++;
                curR = cap2 - flowers[r];
            } else {
                curR -= flowers[r];
            }
        }
        l++;
        r--;
    }
    cout << (countL + countR);
    return 0;
}