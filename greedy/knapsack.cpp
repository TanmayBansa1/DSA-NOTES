// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
	//everything based on the ratio        
    	priority_queue<pair<double,int>> maxi;
	for(int i = 0; i<val.size(); i++){
		maxi.push(double({val[i])/double(wt[i]),i});
	}
	double ans = 0;
	int curr = 0;
	while(!maxi.empty()){
		pair<double,int> max = maxi.top();
		int i = max.second;
		if(curr + wt[i] <= capacity){
			curr += wt[i];
			ans += val[i];
		}else{
			int need = capacity - curr;
			ans += max.first*need;
			curr = capacity;
			break;
		}

	}
	return ans;

    }
};

