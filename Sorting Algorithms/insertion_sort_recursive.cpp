#include <iostream>
using namespace std;

void print_array(int *arr,int n){
    cout<<"\n\n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n\n";
}

void insertion_sort_recursive(int arr[],int size,int current_index = 1){
    if(current_index >= size){
        return;
    }
    int temp = arr[current_index];
    int j = current_index - 1;
    while(j>=0 && arr[j] > temp){
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = temp;

    insertion_sort_recursive(arr,size,current_index + 1);
}

int main(){
    int arr[] =  {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int size = sizeof(arr)/sizeof(arr[0]);
    insertion_sort_recursive(arr,size);
    print_array(arr,size);
    return 0;
}