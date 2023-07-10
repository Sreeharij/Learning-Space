#include <iostream>
using namespace std;

void print_array(int *arr,int n){
    cout<<"\n\n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n\n";
}

void bubble_sort(int* arr,int n){
    int temp = 0;
    bool flag;
    int last_swapped_index = n-1;
    int new_last_swapped_index=0;
    for(int i=0;i<n;i++){
        flag = false;
        
        for(int j=0;j<last_swapped_index;j++){
            if (arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = true;
                new_last_swapped_index = j;
            }
        }
        last_swapped_index = new_last_swapped_index;
        if(!flag){
            break;
        }
    }
    print_array(arr,n);

}

int main(){
    int arr1[] =  {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    bubble_sort(arr1,size1);
    return 0;
}