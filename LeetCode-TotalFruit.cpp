#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int totalFruit2(vector<int>& tree) {
    unordered_map<int, int> count;
    int i, j;
    for (i = 0, j = 0; j < tree.size(); ++j) {
        count[tree[j]]++;
        if (count.size() > 2) {
            if (--count[tree[i]] == 0) count.erase(tree[i]);
            i++;
        }
    }
    return j - i;
}

int totalFruit(vector<int>& tree) {
    int ans = 0;
    int i = 0;
    unordered_map<int, int> counter;
    for (int j = 0; j < tree.size(); j++) {
        counter[tree[j]] += 1;
        while (counter.size() >= 3) {
            counter[tree[i]] -= 1;
            if (counter[tree[i]] == 0) counter.erase(tree[i]);
            i++;
        }
        ans = max(ans, j - i + 1);
    }
    return ans;
}

int main() {
    vector<vector<int>> trees = {
        {1, 2, 1},
        {0, 1, 2, 2},
        {1, 2, 3, 2, 2},
        {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4},
        {0, 1, 6, 6, 4, 4, 6},
        {1, 2, 1, 1, 2, 2, 3, 3, 3, 3, 2, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
    };
    for (auto t : trees) cout << totalFruit(t) << endl;

    return 0;
}