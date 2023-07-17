#include <bits/stdc++.h>
using namespace std;

void print_array(int *arr,int n){
    cout<<"\n\n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n\n";
}

void count_sort(int arr[],int size){
    int *max_val = max_element(arr,arr+size);
    int *min_val = min_element(arr,arr+size);
    int range = *max_val - *min_val + 1; 
    int freq_arr[range];
    memset(freq_arr,0,sizeof(freq_arr));
    for(int i=0;i<size;i++){
        freq_arr[arr[i] - *min_val]++;
    }
    int k=0;
    for(int i=0;i<range;i++){
        while(freq_arr[i]--){
            arr[k++] = i + *min_val;
        }
    }

    print_array(arr,size);
}

int main() {
    int arr1[] = {10,9,8,7,6,5,4,3,2,1};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    count_sort(arr1,size1);

    return 0;
}