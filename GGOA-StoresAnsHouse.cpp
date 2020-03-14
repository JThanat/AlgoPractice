/**
 * Source: https://leetcode.com/discuss/interview-question/350248/Google-or-Summer-Intern-OA-2019-or-Stores-and-Houses
*/
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> houses = {2, 4, 2};
    vector<int> stores = {5, 1, 2, 3};
    sort(stores.begin(), stores.end());

    vector<int> ans;
    vector<int>::iterator it;
    int pos;
    for (int h : houses) {
        it = lower_bound(stores.begin(), stores.end(), h);
        if (*it == h) {
            ans.push_back(*it);
        } else {
            pos = (it - stores.begin());
            ans.push_back(abs(stores[pos] - h) < abs(stores[pos - 1] - h) ? stores[pos] : stores[pos - 1]);
        }
    }

    for (auto a : ans) cout << a << " ";

    return 0;
}