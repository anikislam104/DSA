//
// Created by aniki on 12/26/2022.
//
#include "iostream"
using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[],int low,int high){
    int pivot=arr[high];
    int i=low-1;
    for(int j=low;j<high;j++){
        if(arr[j]<pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return i+1;
}

int* quick_sort(int arr[], int low, int high){
    if(low<high){
        int partition_index= partition(arr,low,high);
        quick_sort(arr,low,partition_index-1);
        quick_sort(arr,partition_index+1,high);
    }
    else{
        return arr;
    }
}


int main(){
    int arr[] = {23,11,9,29,2,14,18};
    int n = sizeof(arr)/sizeof(arr[0]);
    int* sorted_array = quick_sort(arr, 0,n-1);
    for(int i=0;i<n;i++){
        cout<<sorted_array[i]<<" ";
    }
    return 0;
}