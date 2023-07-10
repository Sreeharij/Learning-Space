#include <iostream>
using namespace std;

void print_array(int *arr,int n){
    cout<<"\n\n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n\n";
}

void insertion_sort(int* arr,int n){
    int current_value = 0;
    int i,j;
    for(i=1;i<n;i++){
        current_value = arr[i];
        for(j=i-1;j>=0;j--){
            if(current_value<arr[j]){
                arr[j+1] = arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1] = current_value;
    }   
    print_array(arr,n);
}

int main(){
    int arr1[] =  {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    insertion_sort(arr1,size1);
    return 0;
}