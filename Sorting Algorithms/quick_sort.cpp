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

void push_median_to_left(int arr[],int left,int right){
    int centre = (left + right)/2;
    if(arr[centre] < arr[left]){
        swap(arr,left,centre);
    }
    if(arr[right] < arr[left]){
        swap(arr,left,right);
    }
    if(arr[centre] < arr[right]){
        swap(arr,left,centre);
    }
    else{
        swap(arr,left,right);
    }
}

void quick_sort(int arr[],int left,int right){
    if(left >= right){
        return;
    }
    push_median_to_left(arr,left,right);
    int pivot_idx = left;
    int left_ptr = left + 1;
    int right_ptr = right;

    while(left_ptr <= right_ptr){ //THE LESS THAN OR 'EQUAL TO' CONDITION IS A MUST, ELSE IT WILL RESULT IN ERROR
        while(left_ptr <= right && arr[left_ptr] <= arr[pivot_idx]){
            left_ptr++;
        }
        while(right_ptr >= pivot_idx && arr[right_ptr] > arr[pivot_idx]){
            right_ptr--;
        }
        if(left_ptr < right_ptr){
            swap(arr,left_ptr,right_ptr);
        }
        
    }
    swap(arr,pivot_idx,right_ptr);
    quick_sort(arr,left,right_ptr -1 );
    quick_sort(arr,right_ptr+1,right);

}

int main(){
    int arr[] =  {2,4,7,4,-3,0,5,5,3,2,0,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    quick_sort(arr,0,size - 1);
    print_array(arr,size);
    return 0;
}