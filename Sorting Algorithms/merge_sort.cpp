//MERGE SORT ALGORITHM WITH OPTIMISED ARRAY CREATION
#include <iostream>
using namespace std;

void print_array(int *arr,int n){
    cout<<"\n\n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n\n";
}

void merge(int arr[],int left,int mid,int right,int left_arr[],int right_arr[]){
    int left_size = mid - left + 1;
    int right_size = right - mid;
    
    for(int i=0;i<left_size;i++){
        left_arr[i] = arr[left + i];
    }
    for(int j=0;j<right_size;j++){
        right_arr[j] = arr[mid + 1 + j];
    }
    
    int i = 0,j = 0;
    int k = left;
    while(i<left_size && j<right_size){
        if(left_arr[i] <= right_arr[j]){
            arr[k++] = left_arr[i++];
        }
        else{
            arr[k++] = right_arr[j++];
        }
    }
    while(i < left_size){
        arr[k++] = left_arr[i++];
    }
    while(j < right_size){
        arr[k++] = right_arr[j++];
    }
}

void merge_sort(int arr[],int left,int right,int left_arr[],int right_arr[]){
    if(left < right){
        int mid = (left + right)/2;
        
        merge_sort(arr,left,mid,left_arr,right_arr);
        merge_sort(arr,mid+1,right,left_arr,right_arr);
        merge(arr,left,mid,right,left_arr,right_arr);
    }
}


int main(){
    int arr[] =  {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int size = sizeof(arr)/sizeof(arr[0]);
    int left_arr[size],right_arr[size];
    merge_sort(arr,0,size-1,left_arr,right_arr);
    print_array(arr,size);
    return 0;
}
