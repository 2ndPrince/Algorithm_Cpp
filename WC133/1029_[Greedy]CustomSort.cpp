// 1029. Two City Scheduling
// https://leetcode.com/contest/weekly-contest-133/problems/two-city-scheduling/

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int res = 0;
        sort(costs.begin(), costs.end(), [](vector<int> &a, vector<int> &b){ return a[0] - a[1] < b[0] - b[1]; });
        int cnt = 0;
        for (vector<int> &cost : costs) {
            if (cnt < costs.size() / 2) {
                res += cost[0];
            } else {
                res += cost[1];
            }
            cnt++;
        }
        return res;
    }
};
