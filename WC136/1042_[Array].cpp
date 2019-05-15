// 1042
// https://leetcode.com/contest/weekly-contest-136/problems/flower-planting-with-no-adjacent/
// Solution from neal_wu

class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<int> answers(N, 0);
        vector<vector<int>> adj(N, vector<int>());

        for (auto &edge : paths) {
            edge[0]--;
            edge[1]--;
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        for (int i = 0; i < N; i++) {
            vector<bool> ok(5, true);

            for (int neighbor : adj[i])
                ok[answers[neighbor]] = false;

            for (int c = 1; c <= 4; c++)
                if (ok[c]) {
                    answers[i] = c;
                    break;
                }
        }

        return answers;
    }
};
