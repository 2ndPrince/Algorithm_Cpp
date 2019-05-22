// 1048. Longest String Chain
/*
Input: ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: one of the longest word chain is "a","ba","bda","bdca".
*/

// Solution from Neal_Wu

bool is_predecessor(const string &a, const string &b) {
    if (a.size() + 1 != b.size())
        return false;

    int n = a.size();

    for (int i = 0; i <= n; i++)
        if (a == b.substr(0, i) + b.substr(i + 1))
            return true;

    return false;
}

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();

        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.size() < b.size();
        });

        vector<vector<bool>> can(n, vector<bool>(n, false));

        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                can[i][j] = is_predecessor(words[i], words[j]);

        vector<int> dp(n, 1);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++)
                if (can[j][i])
                    dp[i] = max(dp[i], dp[j] + 1);
        }

        return *max_element(dp.begin(), dp.end());
    }
};
