#include <math.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    vector<pair<float, int>> v;
    vector<vector<int>> ans(K);
    float dist;
    for (int i = 0; i < points.size(); i++) {
        dist = sqrt(points[i][0] * points[i][0] + points[i][1] * points[i][1]);
        v.push_back(make_pair(dist, i));
    }

    priority_queue<pair<float, int>, vector<pair<float, int>>, std::greater<pair<float, int>>> pq(v.begin(), v.end());

    for (int i = 0; i < K; i++) {
        auto p = pq.top();
        ans[i] = points[p.second];
    }
    return ans;
}
class NodeComp {
    public:
        bool operator() (int a, int b) const {
            return a > b;
        }
};

int main() {
    int i = 1 << 3; // 1 10 100
    cout << i << endl;
    cout << (1 << 1) << endl;
    return 0;
}