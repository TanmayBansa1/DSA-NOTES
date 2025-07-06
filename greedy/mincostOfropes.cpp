class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
 	
	priority_queue<int, vector<int> , greater<int>> mini;
	for(auto x:arr){
		mini.push(x);
	}
	int ans =0;

	while(mini.size()>1){
		int a = mini.top();
		mini.pop();
		int b = mini.top();
		mini.pop();

		ans += a+b;

		mini.push(a+b);
	}

	return ans;
    }
};
