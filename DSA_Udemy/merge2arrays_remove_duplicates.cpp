//CODE FOR MERGING 2 ARRAYS WHILE REMOVING THE DUPLICATES

#include <iostream>
using namespace std;

int * merge(int arr1[] ,int arr2[],int size1,int size2,int total_size){
  int* new_arr = new int[total_size];
  int current_idx = 0,i=0,j=0;
  while (i<size1 && j<size2){
    if(arr1[i]==arr2[j]){
      if (current_idx==0 || arr1[i]!=new_arr[current_idx-1]){
        new_arr[current_idx] = arr1[i];
        current_idx++;
      }
      i++;
      j++;
    }
    else if(arr1[i]<arr2[j]){
        if(arr1[i]!=new_arr[current_idx-1]){
            new_arr[current_idx] = arr1[i];
            current_idx++;
        }
        i++;
    }
    else{
        if(arr2[j]!=new_arr[current_idx-1]){
            new_arr[current_idx] = arr2[j];
            current_idx++;
        }
        j++;
    }
  }
  while(i<size1){
    new_arr[current_idx] = arr1[i];
    i++;
    current_idx++;
  }
  while(j<size2){
    new_arr[current_idx] = arr2[j];
    j++;
    current_idx++;
  }

  return new_arr;
}

int main()
{
  int arr1[10] = {1, 1, 2, 8, 10, 12, 14, 16, 18, 20};
  int arr2[5] = {1, 2, 2, 7, 9};

  int total_size = 15;
  int* new_arr = merge(arr1,arr2,10,5,total_size);
  for(int i=0;i<total_size;i++){
    cout<<new_arr[i]<<" ";
  }  
  cout<<endl;
  return 0;
}
