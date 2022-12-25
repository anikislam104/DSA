//
// Created by aniki on 12/24/2022.
//
#include "iostream"
using namespace std;

int linear_search(int arr[], int n, int x)
{
    int index=-1;
    for (int i=0;i<n;i++){
        if(arr[i]==x){
            index=i;
            break;
        }
    }
    return index;
}

int main(){
    int arr[] = {7,2,5,3,1,4,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x ;
    cout<<"Enter the number to be searched: ";
    cin>>x;
    int result = linear_search(arr, n, x);
    if(result == -1){
        cout << "Element is not present in array";
    }
    else{
        cout << "Element is present at index " << result;
    }
    return 0;
}

//Time complexity: O(n)
//Space complexity: O(1)
//Average case: O(n/2)
//Worst case: O(n)
//Successive comparisons: n-1
