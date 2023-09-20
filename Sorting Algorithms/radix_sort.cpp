#include <iostream>
#include <vector>
using namespace std;

void print_array(int *arr,int n){
    cout<<"\n\n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n\n";
}

void radix_sort(int arr[],int size){
    int max_number = arr[0];
    for(int i=1;i<size;i++){
        max_number = max_number > arr[i] ? max_number : arr[i];
    }
    int exponent = 1;
    int output_arr[size];
    int required_idx;
    while(max_number/exponent > 0){
        vector<int> count(10,0);
        for(int i=0;i<size;i++){
            count[(arr[i]/exponent)%10]++;
        }
        for(int i=1;i<size;i++){
            count[i] += count[i-1];
        }
        for(int i=size-1;i>=0;i--){
            required_idx = count[(arr[i]/exponent)%10] - 1;
            output_arr[required_idx] = arr[i];
            count[(arr[i]/exponent)%10]--;
        }
        for(int i=0;i<size;i++){
            arr[i] = output_arr[i];
        }
        exponent *= 10;
    }
    print_array(arr,size);
}

int main(){
    int arr1[] =  {170, 45, 75, 90, 802, 24, 2, 66,26,106};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    radix_sort(arr1,size1);
    return 0;
}