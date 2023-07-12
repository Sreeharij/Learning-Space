//FINDING INTERSECTION IN SORTED ARRAY
#include <iostream>
using namespace std;

int* intersection(int arr1[],int arr2[],int size1,int size2,int &intersection_size){
    int i=0,j=0,k=0;
    int *temp_arr = new int[size1+size2];
    while(i<size1 && j<size2){
        if(arr1[i] < arr2[j]){
            i++;
        }
        else if(arr2[j] < arr1[i]){
            j++;
        }
        else{
            temp_arr[k++] = arr1[i];
            i++;
            j++;
        }
    }
    intersection_size = k;
    int *intersection_array = new int[k];
    for(int i=0;i<k;i++){
        intersection_array[i] = temp_arr[i];
    }
    delete[] temp_arr;
    return intersection_array;
}

int main(){
    int arr1[] = {3,4,5,6,10};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    int arr2[] = {2,4,5,7,10};
    int size2 = sizeof(arr2)/sizeof(arr2[0]);

    int intersection_size = 0;

    int *intersection_array = intersection(arr1,arr2,size1,size2,intersection_size);
    for(int i=0;i<intersection_size;i++){
        cout<<intersection_array[i]<<" ";
    }cout<<endl;
    return 0;
}