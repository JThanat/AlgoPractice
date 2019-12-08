#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// https://leetcode.com/discuss/interview-question/352458/

vector<string> parseString(string &s) {
    vector<string> v;
    string out = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ',') {
            v.push_back(out);
            out = "";
        } else {
            out += s[i];
        }
    }
    v.push_back(out);
    return v;
}

int eval(string A) {
    unordered_map<char, int> m;
    char smallest = A[0];
    for (char c : A) {
        if (int(c) < smallest) smallest = c;
        m[c]++;
    }
    return m[smallest];
}

void ONMSol() {
    string A = "abcd,aabc,bd";
    string B = "aaa,aa";
    vector<string> AS = parseString(A);
    vector<string> BS = parseString(B);
    vector<int> minA;
    vector<int> minB;
    vector<int> ans;
    int count;

    for (string s : AS) minA.push_back(eval(s));
    for (string s : BS) minB.push_back(eval(s));
    // O(NM)
    for (int i = 0; i < BS.size(); i++) {
        count = 0;
        for (int j = 0; j < AS.size(); j++) {
            if (minB[i] > minA[j]) count++;
        }
        ans.push_back(count);
    }
    for (auto a : ans) {
        cout << a << " ";
    }
}

void ONPlusMSol() {
    string A = "abcd,aabc,bd";
    string B = "aaa,aa";
    vector<string> AS = parseString(A);
    vector<string> BS = parseString(B);
    vector<int> freqs(11);
    vector<int> prefixFreqs(11);
    vector<int> ans;
    // O(N)
    for(string s: AS) {
        int freq = eval(s);
        freqs[freq]++; // count frequency of min
    }

    for(int i = 1; i < 11 ; i++) {
        prefixFreqs[i] = freqs[i] + freqs[i-1];
    }
    // O(M)
    for(string s:BS) {
        int freq = eval(s);
        ans.push_back(prefixFreqs[freq-1]);
    }

    for (auto a : ans) {
        cout << a << " ";
    }
}

int main() {
    // ONMSol();
    ONPlusMSol();
    return 0;
}