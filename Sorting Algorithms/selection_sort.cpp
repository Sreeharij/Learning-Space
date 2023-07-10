#include <iostream>
using namespace std;

void print_array(int *arr,int n){
    cout<<"\n\n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n\n";
}

void selection_sort(int *arr, int n){
    int temp = 0;
    int current_min_idx;
    for(int i=0;i<n-1;i++){
        current_min_idx = i;
        for(int j=i+1;j<n;j++){
            current_min_idx = arr[j] < arr[current_min_idx] ? j : current_min_idx;
        }
        if(i!=current_min_idx){    //VERY SMALL OPTIMISATION
            temp = arr[i];
            arr[i] = arr[current_min_idx];
            arr[current_min_idx] = temp;
        }
    }
    print_array(arr,n);
}

int main() {
    int arr1[] =  {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    selection_sort(arr1,size1);

    return 0;
}