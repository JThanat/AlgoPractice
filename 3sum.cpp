#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
        int target = -nums[i];
        int front = i + 1;
        int back = nums.size() - 1;
        while (front < back) {
            int sum = nums[front] + nums[back];
            if (sum < target)
                front++;
            else if (sum > target)
                back--;
            else {
                vector<int> triplet{nums[front], nums[i], nums[back]};
                ans.push_back(triplet);
                while (front < back && nums[front] == triplet[0]) front++;
            }
        }
        while (i + 1 < nums.size() && nums[i] == nums[i + 1]) i++;  // the last i will be added by for loop i++
    }
    return ans;
}
