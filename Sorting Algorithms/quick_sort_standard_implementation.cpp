//STANDARD IMPLEMENTATION OF QUICK SORT
#include <iostream>
using namespace std;

void print_array(int *arr,int n){
    cout<<"\n\n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n\n";
}

void swap(int arr[],int first,int second){
    int temp = arr[first];
    arr[first] = arr[second];
    arr[second] = temp;
}

int partition(int arr[],int left,int right){
    int pivot_idx = right;
    int i = left - 1;
    for(int j=left;j<right;j++){
        if(arr[j] <= arr[pivot_idx]){
            i += 1;
            swap(arr,i,j);
        }
    }
    i += 1;
    swap(arr,i,right);
    return i;
}

void quick_sort(int arr[],int left,int right){
    if(left >= right){
        return;
    }
    int pivot_idx = partition(arr,left,right);
    quick_sort(arr,left,pivot_idx - 1);
    quick_sort(arr,pivot_idx + 1,right);
}

int main() {

    int arr[] =  {2,4,7,4,-3,0,5,5,3,2,0,1};
    // int arr[] = {5,4,3,2,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    quick_sort(arr,0,size-1);
    print_array(arr,size);

    return 0;
}