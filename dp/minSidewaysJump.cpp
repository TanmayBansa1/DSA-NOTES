class Solution {
public:
    int solve(vector<int>& obstacles, int i, int n, int j) {
        if (i >= n) {
            return 0;
        }

        if (obstacles[i + 1] != j) {
            return solve(obstacles, i + 1, n, j);
        } else {
            int ans = INT_MAX;
            for (int k = 1; k <= 3; k++) {
                if (j != k && obstacles[i] != k) {
                    ans = min(ans, 1 + solve(obstacles, i, n, k));
                }
            }
            return ans;
        }
    }
    int tabulation(vector<int>& obstacles) {
        int n = obstacles.size()-1;
        vector<vector<int>> dp(4, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; i--) {

            for (int j = 1; j <= 3; j++) {
                if(obstacles[i] == j){
                    dp[j][i] = INT_MAX;
                }
                if (obstacles[i + 1] != j && i+1 <= n) {
                    dp[j][i] = dp[j][i+1];
                } else {
                    int ans = INT_MAX;
                    for (int k = 1; k <= 3; k++) {
                        if (j != k && obstacles[i] != k) {
                            ans = min(ans, 1 + dp[k][i+1]);
                        }
                    }
                    dp[j][i] = ans;
                }
            }
        }
        return dp[2][0];
    }
    int minSideJumps(vector<int>& obstacles) {
        // return solve(obstacles, 0, obstacles.size(), 2);

        return tabulation(obstacles);
    }
};