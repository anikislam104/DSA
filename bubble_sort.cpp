//
// Created by aniki on 12/25/2022.
//
#include "iostream"
using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int* bubble_sort(int arr[], int n)
{
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
    return arr;
}

int main(){
    int arr[] = {7,2,5,3,1,4,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int *sorted_array = bubble_sort(arr, n);
    for(int i=0;i<n;i++){
        cout<<sorted_array[i]<<" ";
    }
    return 0;
}

//Time complexity: O(n^2)
//Space complexity: O(1)
//Average case: O(n^2)