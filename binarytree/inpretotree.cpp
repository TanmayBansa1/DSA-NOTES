//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void printPostOrder(Node *root)
{
    if (root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution
{
public:
    int findpos(int in[], int rootdata, int n, int s, int e)
    {
        for (int i = s; i <= e; i++)
        {
            if (in[i] == rootdata)
                return i;
        }
        return -1;
    }
    Node *solve(int in[], int pre[], int n, int index, int si, int ei)
    {

        // base case
        if (index >= n || si > ei)
        {
            return NULL;
        }

        int rootdata = pre[index++];
        int position = findpos(in, rootdata, n, si, ei);

        Node *root = new Node(rootdata);

        root->left = solve(in, pre, n, index, si, position - 1);
        root->right = solve(in, pre, n, index, position + 1, ei);

        return root;
    }
    Node *buildTree(int in[], int pre[], int n)
    {
        // Code here

        Node *ans = solve(in, pre, n, 0, 0, n - 1);

        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int inorder[n], preorder[n];
        for (int i = 0; i < n; i++)
            cin >> inorder[i];
        for (int i = 0; i < n; i++)
            cin >> preorder[i];
        Solution obj;
        Node *root = obj.buildTree(inorder, preorder, n);
        printPostOrder(root);
        cout << endl;
    }
}

// } Driver Code Ends

    Node* solve(int in[],int post[], int n, int& postindex , int inorder_start , int  inorder_end)
    {
        if(postindex < 0 || inorder_start > inorder_end)
        {
            return NULL;
        }
        
        int element = post[postindex];
        Node* root = new Node(element);
        
        int position = findposition(element,in ,inorder_start , inorder_end);
        
        postindex--;
        root-> right = solve(in , post , n , postindex, position + 1 , inorder_end);
        root->left = solve(in,post,n,postindex, inorder_start , position - 1);
        
        
        return root;
    }