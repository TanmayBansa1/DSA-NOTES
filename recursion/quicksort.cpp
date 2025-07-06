#include<iostream>
using namespace std;

int partition(int *arr, int s, int e){
    int count = 0;
    int pivot = arr[s];
    for(int i = s+1; i<=e; i++){
        if(arr[i]<arr[s]){
            count++;
        }
    }
    int pivotIndex = s+count;

    swap(arr[pivotIndex], arr[s]);

    // int i = s;
    // int j = e;

    while(s < pivotIndex && e>pivotIndex){

        if(arr[s] < pivot && arr[e] > pivot){
            s++;
            e--;
        }
        else if(arr[s] < pivot && arr[e] < pivot){
            s++;
        }
        else if(arr[s] >= pivot && arr[e] <= pivot){
            swap(arr[s], arr[e]);
            s++;
            e--;
        }
        else{
            e--;
        }
    }
    return pivotIndex;
}

void quickSort(int *arr, int s, int e){

    //base case
    if(s>=e){
        return;
    }

    int p = partition(arr,s,e);

    quickSort(arr, s, p-1);
    quickSort(arr, p+1, e);


}
int main()
{
    int arr[7] = {9 ,9 ,9 ,8, 2, 3, -6 };

    quickSort(arr, 0, 10);

    for(auto c:arr){
        cout<<c<<" ";
    }
    return 0;
}