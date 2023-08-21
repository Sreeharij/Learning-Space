#include <iostream>
using namespace std;

void print_array(int *arr,int n){
    cout<<"\n\n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n\n";
}

void bubble_sort_recursive(int arr[],int size,int last_swapped_index,int level = 0,bool flag = false){
    if(level >= size - 1){
        return;
    }
    int new_swapped_index = 0;
    for(int j=0;j<last_swapped_index;j++){
        if(arr[j] > arr[j+1]){
            int temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
            flag = true;
            new_swapped_index = j;
            
        }
    }
    last_swapped_index = new_swapped_index;
    if(!flag){
        return;
    }
    bubble_sort_recursive(arr,size,last_swapped_index,level + 1,false);

}

int main() {

    int arr[] =  {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int size = sizeof(arr)/sizeof(arr[0]);
    bubble_sort_recursive(arr,size,size - 1,0,false);
    print_array(arr,size);

    return 0;
}