class Solution {
public:
    int solve(int n, int i, int &ans1){

        //base case
        if(i >= n){
            return 0;
        }
        int ans = INT_MAX;
        for(int j = i; j<=n; j++){

            ans = min(ans, max(j+solve(j-1,i,ans1), j+solve(n,j+1,ans1)));
        }

        return ans;


    }
    int getMoneyAmount(int n) {
        
        //sounds like binary search
        // int ans = 0;
        // return solve(n, 1, ans);


        //tabular
        vector<vector<int>> dp(n+2, vector<int> (n+2,0));
        for(int i = 1; i<=n; i++){
            for(int j = n; j>=1; j--){
                int ans = 1e+9;
                for(int k = j; k<=i; k++){

                    ans = min(ans, max(j+dp[k-1][j], j+dp[j][k+1]));
                
                }
                dp[i][j] = ans;


            }
        }

        return dp[n][1];
    }
};
