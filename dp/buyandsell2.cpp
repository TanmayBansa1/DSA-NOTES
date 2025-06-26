class Solution {
public:

    int solve(vector<int>& prices, int i, int prevbuy, int n){

	//base case
	
	if(i >= n){

		return 0;
	}

	//buy
	//
	//
	int buy = 0;
	if(prevbuy == 0){
		buy = solve(prices, i+1, 1, n) - prices[i];
        int notbuy = solve(prices, i+1, 0, n);
        buy = max(buy,notbuy);
	}

	int sell = 0;
	if(prevbuy == 1){

		sell = solve(prices, i+1, 0,n) + prices[i];
		int notsell = solve(prices, i+1, 1, n);
        sell = max(sell, notsell);

	}

	return max(buy,sell);

	

    }	
    int maxProfit(vector<int>& prices) {
        
        //track prev buy
	//
	//
	//
	
	return solve(prices, 0, 0, prices.size());
    }
};
