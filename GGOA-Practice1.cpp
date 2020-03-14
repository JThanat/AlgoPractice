#include <iostream>
#include <regex>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> A) {
    // Your solution goes here.
    vector<pair<int, int>> v;
    v.push_back(make_pair(A[0], A[0]));  // min max
    for (int i = 1; i < A.size(); i++) {
        int minCompat = v.size();
        int minDiff = INT_MAX;
        for (int j = 0; j < v.size(); j++) {
            if(A[i] > v[j].second) continue; // taller than the tallest then skip
            else if(A[i] < v[j].first) { // shorter than all vj
                if(minDiff > A[i] - v[j].first) {
                    minDiff = A[i] - v[j].first;
                    minCompat = j;
                }
            }
        }
        for(auto p : v) {
            cout << p.first << " " << p.second << endl;
        }
        cout << endl;
        if(minCompat == v.size()) {
            v.push_back(make_pair(A[i],A[i]));
        } else {
            v[minCompat].first = A[i];
        }
    }
    return v.size();
}

int main() {
    // Read in from stdin, solve the problem, and write answer to stdout.
    vector<int> A = {5, 4, 3, 6, 1};
    cout << solution(A);
}