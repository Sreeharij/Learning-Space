#include <iostream>
using namespace std;

int* get_difference(int arr1[],int arr2[],int size1,int size2, int &difference_size){
    int *temp_arr = new int[size1];
    int i=0,j=0,k=0;

    while(i<size1 && j<size2){
        if(arr1[i]<arr2[j]){
            temp_arr[k++] = arr1[i++];
        }
        else if(arr1[i] > arr2[j]){
            j++;
        }
        else{
            i++;
            j++;
        }

    }
    while(i < size1){
        temp_arr[k++] = arr1[i++];
    }
    difference_size = k;

    int *difference_array = new int[difference_size];
    for(int i=0;i<difference_size;i++){
        difference_array[i] = temp_arr[i];
    }
    delete[] temp_arr;
    return difference_array;
    
}


int main(){
    int arr1[] = {3,4,5,6,10};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    int arr2[] = {2,4,5,7,10};
    int size2 = sizeof(arr2)/sizeof(arr2[0]);

    int difference_size = 0;

    int *difference_array = get_difference(arr1,arr2,size1,size2,difference_size);
    for(int i=0;i<difference_size;i++){
        cout<<difference_array[i]<<" ";
    }cout<<endl;

    return 0;
}