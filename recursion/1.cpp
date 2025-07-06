#include<iostream>
using namespace std;

int fibonacci(int n){
    //base case
    if(n<=1){
		return 0;
	}
    if(n==2){
		return 1;
	}
	return fibonacci(n-1)+fibonacci(n-2);
}
bool binarySearch(int arr[], int s, int e, int k){
    
    
    if(s>e){
        return false;
    }
    int mid = s +(e-s)/2;
        if(arr[mid] == k){
            return true;
        }
        else if(arr[mid] < k){
            binarySearch(arr, mid+1, e,k);
        }
        else{
            binarySearch(arr,s,mid-1,k);
        }
        
    
}
bool checkPalindrome(string str, int s, int e){
	//base case

	if(s>e){
		return true;
	}
	if(str[s] != str[e]){
		return false;
	}
	else{
		return checkPalindrome(str, s+1, e-1);
	}
}
void bubblesort(int *arr, int n){
//base case
	if(n == 0 || n == 1)
		return;
	
	//first case solve

	for(int i = 0; i<n-1; i++){
		if(arr[i]>arr[i+1]){
			swap(arr[i],arr[i+1]);
		}
	}
	//recursive call
	bubblesort(arr, n-1);

	
}
int power(int a, int b){

	if(b == 0){
		return 1;
	}
	if(b == 1){
		return a;
	}

	int ans = power(a, b/2);

	if(b&1){
		return a*ans*ans;
	}
	else{
		return ans*ans;
	}
}

bool isSorted(int *arr, int size){
	//base case

	if(size == 0 || size == 1){
		return 1;
	}
    if(arr[0]>arr[1]){
		return 0;
	}
	else{
		return isSorted(arr+1,size-1);
	}
}
void saydigit(int n, string arr[]){
	//base case

	if(n==0){
		return;
	}

	int digit = n%10;
	n = n/10;

	saydigit(n,arr);

	cout<<arr[digit]<<" ";
}
int sumofArray(int *arr, int n){
	//base case
	if(n == 0){
		return 0;
	}
	int ans = arr[0];
	ans += sumofArray(arr+1,n-1);
	return ans;

}
int main()
{
	int n;
	cin>>n;
    string arr[10] = {"zero","one", "two", "three", "four", "five", "six", "seven","eight","nine"};
	cout<< fibonacci(n);

	int x = 420;
	saydigit(x,arr);
    int ans =0;
	int arr1[5]= {2,30,4,5,6};
	cout<<isSorted(arr1,5)<<endl;
	cout<<sumofArray(arr1,5);
	bubblesort(arr1,5);
	for(auto x:arr1){
		cout<<x;
	}

	return 0;
}