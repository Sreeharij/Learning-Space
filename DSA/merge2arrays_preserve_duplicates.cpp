//CODE FOR MERGING 2 ARRAYS WHILE PRESERVING THE DUPLICATES


#include <bits/stdc++.h>
using namespace std;

int * merge(int arr1[] ,int arr2[],int size1,int size2,int total_size){
  int* new_arr = new int[total_size];
  int current_idx = 0,i=0,j=0;
  while (1){
    if (current_idx>=total_size){
      break;
    }
    while(arr1[i]<=arr2[j] && i<size1){
      new_arr[current_idx] = arr1[i];
      i++;
      current_idx++;
    }
    if (current_idx>=total_size){
      break;
    }
    while(arr2[j]<arr1[i] && j<size2){
      new_arr[current_idx] = arr2[j];
      current_idx++;
      j++;
    }
  }
  return new_arr;
}

int main()
{
  int arr1[10] = {1, 1, 6, 8, 10, 12, 14, 16, 18, 20};
  int arr2[5] = {1, 3, 5, 7, 9};

  int total_size = 15;
  int* new_arr = merge(arr1,arr2,10,5,total_size);
  for(int i=0;i<total_size;i++){
    cout<<new_arr[i]<<" ";
  }  
  cout<<endl;
  delete[] new_arr;
  return 0;
}
