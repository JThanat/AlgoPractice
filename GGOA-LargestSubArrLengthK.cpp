#include<iostream>
#include<vector>

using namespace std;

int main() {
    // https://leetcode.com/discuss/interview-question/352459/
    // our contiguos sub array could start from idx 0 to N-K at most
    // we can only to find max starting point because all of the array member are distinct
    // when we know the idx just return A[idx..idx+K]
    vector<int> A = {1,4,3,2,5};
    int K = 4;
    int maxIdx = 0;
    for(int i = 0; i <= A.size() - K; i++) {
        if(A[i] > A[maxIdx]) maxIdx = i;
    }
    for(int i = maxIdx; i < maxIdx + K; i++) {
        cout << A[i] << " ";
    }
    return 0;
}