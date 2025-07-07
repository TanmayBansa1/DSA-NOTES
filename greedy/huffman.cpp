
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    
    Node(int d){
        this->data = d;
        left = nullptr;
        right = nullptr;
    }
};
class cmp{
    public:
    
    bool operator()(Node* &a, Node* &b){
        return a->data > b->data;
    }
};
class Solution
{
	public:
	    void traverse(Node* root, vector<string> &ans, string path){
	        
	        //if leaf node encountered store the ans
	        if(root->left == nullptr && root->right == nullptr){
	            ans.push_back(path);
	            return;
	        }
	        
	        traverse(root->left,ans,path+'0');
	        traverse(root->right,ans,path+'1');
	    }
	    
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    // Code here
		    priority_queue<Node*, vector<Node*>, cmp> mini;
		    //created the priority queue to help build the tree
		    
		    for(int i = 0; i<N; i++){
		        mini.push(new Node(f[i]));
		    }
		    
		    while(mini.size()>1){
		        
		        Node* left = mini.top();
		        mini.pop();
		        Node* right = mini.top();
		        mini.pop();
		        
		        
		        Node* parent = new Node(left->data + right->data);
		        parent->left = left;
		        parent->right = right;
		        mini.push(parent);
		        
		    }
		    
		    Node* root = mini.top();
		    vector<string> ans;
		    string temp = "";
		    traverse(root,ans,temp);
		    
		    return ans;
		    
		}
};


