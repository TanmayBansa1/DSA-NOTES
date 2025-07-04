
class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string &s) {
        // code here
       
	string ans = "";
	string temp = "";
	for(int i = s.length()-1; i>=0; i--){

		if(s[i] == ' '){
			reverse(temp.begin(), temp.end());
			ans= ans +temp;
			if(temp != ""){
			    
			ans.push_back(' ');
			}
			temp = "";
		}

		else{
			temp.push_back(s[i]);
		}
	}
	reverse(temp.begin(), temp.end());
	ans = ans+temp;
// 	ans.slice(0);
    if(ans.back() == ' '){
        
	ans.pop_back();
    }
	return ans;
    }
};
