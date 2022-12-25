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

int* selection_sort(int arr[], int n)
{
    for(int i=0;i<n;i++){
        int min=arr[i];
        int index=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<min){
                min=arr[j];
                index=j;
            }
        }
        swap(&arr[i],&arr[index]);
    }
    return arr;
}

int main(){
    int arr[] = {23,11,9,29,2,14,18};
    int n = sizeof(arr)/sizeof(arr[0]);
    int *sorted_array = selection_sort(arr, n);
    for(int i=0;i<n;i++){
        cout<<sorted_array[i]<<" ";
    }
    return 0;
}

//Time complexity: O(n^2)
//Space complexity: O(1)
//Average case: O(n^2)
//Worst case: O(n^2)
//Successive comparisons: n(n-1)/2