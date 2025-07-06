#include <iostream>
using namespace std;

void merge(int *arr, int s, int e)
{
    int mid = s+(e-s)/2;
    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *arr1 = new int[len1];
    int *arr2 = new int[len2];

    int k = s;
    for (int i = 0; i < len1; i++)
    {
        arr1[i] = arr[k++];
    }

    int l = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        arr2[i] = arr[l++];
    }
    // merge the two created arrays
    int index1 = 0;
    int index2 = 0;
    k = s;
    while (index1 < len1 && index2 < len2)
    {

        if (arr1[index1] < arr2[index2])
        {
            arr[k++] = arr1[index1++];
        }
        else
        {
            arr[k++] = arr2[index2++];
        }
    }

    while (index1 < len1)
    {
        arr[k++] = arr1[index1++];
    }
    while (index2 < len2)
    {
        arr[k++] = arr2[index2++];
    }
}
void mergeSort(int *arr, int s, int e)
{

    // base case
    if (s >= e)
    {
        return;
    }
    int mid = s + (e-s)/2;
    // leftpart sort
    mergeSort(arr, s, mid);
    // rightpart sort
    mergeSort(arr, mid + 1, e);

    merge(arr, s, e);
}
int main()
{
    int arr[6] = {2, 5, 8, 7, 10, 9};

    mergeSort(arr, 0, 5);

    for(auto c:arr){
        cout<<c;
    }
    return 0;
}