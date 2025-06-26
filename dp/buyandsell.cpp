class Solution {
public:
    int maxProfit(vector<int>& prices) {
 	//can do thisgreedily basically choose the minimum to buy and maximum to sell
	//
	//
	

	int ans = INT_MIN;
	int  b = INT_MAX;
	for(int i = 0; i<prices.size(); i++){

		//choose the mini to buy

		b = min(b, prices[i]);
		ans = max(ans, prices[i] - b);
	}

	return ans;
    }
};
