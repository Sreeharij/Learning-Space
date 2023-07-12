#include <iostream>
#include <algorithm>
using namespace std;

void method1(int arr[],int n){
    //the below conditions take care of all possible edge cases.

    int last_duplicate = 0;
    if (arr[0]==arr[1]){
        last_duplicate = arr[0]==0 ? -1:0;
    }
    else{
        last_duplicate = arr[0];
    }
    for(int i=0;i<n-1;i++){
        if(arr[i] == arr[i+1] && arr[i]!=last_duplicate){
            cout<<arr[i]<<" ";
            last_duplicate = arr[i];
        }
    }
    cout<<endl;
}

void method2(int arr[],int n){
    //using hashing method
    
    int *max_val = max_element(arr,arr+n);
    int *min_val = min_element(arr,arr+n);
    int max_length = *max_val - *min_val + 1;
    int offset = *min_val;
    int hash_arr[max_length] = {0};
    for(int i=0;i<n;i++){
        hash_arr[arr[i]-offset]++; 
    }
    for(int i=0;i<max_length;i++){
        if(hash_arr[i]>1){
            cout<<i + offset<<" ";
        }
    }
    cout<<endl;
}

void method3(int arr[],int n){
    int i=0;
    while(i<n-1){
        if(arr[i]==arr[i+1]){
            int j=1;
            while((i+j+1<n) && arr[i+j]==arr[i+j+1]){
                j++;
            }
            i += j;
            cout<<arr[i]<<" ";
        }
        i++;
    }
    cout<<endl;
}

int main(){
    int arr[] = {0,-1,-1,8,8,8,10,12,15,15,15,15,20,20};
    int n =sizeof(arr)/sizeof(arr[0]);
    method1(arr,n);
    method2(arr,n);
    method3(arr,n);
    return 0;
}