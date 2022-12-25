//
// Created by aniki on 12/25/2022.
//
#include "iostream"
using namespace std;

int binary_search(int arr[], int n, int x)
{
    int low=0;
    int high=n-1;
    while (low<=high){
        int mid = (low+high)/2;
        if(x==arr[mid]){
            return mid;
        }
        else if(x>arr[mid]){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
}

int recursive_binary_search(int arr[], int low, int high, int x)
{
    int mid;
    if(low<=high){
//        cout<<low<<" "<<high<<endl;
        mid=(low+high)/2;
        if(x==arr[mid]){
            return mid;
        }
        else if(x<arr[mid]){
            recursive_binary_search(arr,low,mid-1,x);
        }
        else{
            recursive_binary_search(arr,mid+1,high,x);
        }
    } else{
        return -1;
    }
}

int main(){
    int arr[] = {1,2,3,4,5,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x ;
    cout<<"Enter the number to be searched: ";
    cin>>x;
    int result = recursive_binary_search(arr, 0,n-1,x);
    if(result == -1){
        cout << "Element is not present in array";
    }
    else{
        cout << "Element is present at index " << result;
    }
    return 0;
}

//Time complexity: O(log n)
//Space complexity: O(1)
//Average case: O(log n)
//Worst case: O(log n)
//Successive comparisons: log n