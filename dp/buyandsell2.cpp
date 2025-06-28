class Solution {
public:
    int solve(vector<int>& prices, int i, int prevbuy, int n) {

        // base case

        if (i >= n) {

            return 0;
        }

        // buy
        //
        //
        int buy = 0;
        if (prevbuy == 0) {
            buy = solve(prices, i + 1, 1, n) - prices[i];
            int notbuy = solve(prices, i + 1, 0, n);
            buy = max(buy, notbuy);
        }

        int sell = 0;
        if (prevbuy == 1) {

            sell = solve(prices, i + 1, 0, n) + prices[i];
            int notsell = solve(prices, i + 1, 1, n);
            sell = max(sell, notsell);
        }

        return max(buy, sell);
    }
    int maxProfit(vector<int>& prices) {

        // track prev buy
        //
        //
        //

        // return solve(prices, 0, 0, prices.size());

        // tabular
        //
        //
        //

        vector<int> curr(3, 0);
        vector<int> next(3, 0);

        // base case isi>=n so return 0
        //
        //
        int n = prices.size();
        for (int i = n - 1; i >= 0; i--) {

            for (int prevbuy = 1; prevbuy >= 0; prevbuy--) {

                int buy = 0;
                if (prevbuy == 0) {
                    buy = next[1] - prices[i];
                    int notbuy = next[0];
                    curr[0] = max(buy, notbuy);
                }

                int sell = 0;
                if (prevbuy == 1) {

                    sell = next[0] + prices[i];
                    int notsell = next[1];
                    curr[1] = max(sell, notsell);
                }
            }
            next = curr;
        }

        return curr[0];
    }
};
