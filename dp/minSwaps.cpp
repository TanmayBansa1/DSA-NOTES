class Solution {
public:
    int solve(vector<int> &nums1, vector<int> &nums2, bool swapped, int index){
	
	    //base case
	    if(index >= nums1.size()){
		return 0;
	    }	
	    int ans = INT_MAX;
	    //swap krna hai
	    //
	    int prev1 = nums1[index-1];
	    int prev2 = nums2[index-1];

	    if(swapped){
		swap(prev1, prev2);
	    }

	    if(nums1[index] > prev1 && nums2[index] > prev2){
		ans = min(ans,solve(nums1,nums2,0,index+1));

	    }

	    else{
		ans = min(ans, 1 + solve(nums1, nums2, 1, index+1);

	    }

	    return ans;
		



    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        
        int ans = 0;
	//swap krke dekho lol, recursive solution first
	//but can do with performing virtual swaps, not actual on
         
    }
};
