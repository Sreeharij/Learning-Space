#include <bits/stdc++.h>
using namespace std;

class max_heap{
public:
    int *arr;
    int last_idx;
    int max_arr_size = 100;


    max_heap(){
        arr = new int[max_arr_size];
        last_idx = -1;
    }
    ~max_heap(){
        delete[] arr;
    }

    void make_heap_by_insertion(int arr[],int size){
        for(int i=0;i<size;i++){
            this->insert(arr[i]);
        }
    }

    void insert(int x){
        if(last_idx == max_arr_size-1){
            max_arr_size *= 2;
            int *new_arr = new int[max_arr_size];
            for(int i=0;i<=last_idx;i++){
                new_arr[i] = arr[i];
            }
            delete[] arr;
            arr = new_arr;
        }

        last_idx++;
        arr[last_idx] = x;
        int i = last_idx;
        int temp = arr[last_idx];
        while(i > 0 && arr[(i-1)/2] < temp){
            arr[i] = arr[(i-1)/2];
            i = (i-1)/2;
        }
        arr[i] = temp;
    }          

    void display(){
        for(int i=0;i<=last_idx;i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }

    void swap(int& a,int& b){
        int temp = a;
        a = b;
        b = temp;
    }

    int delete_max(){
        if(last_idx == -1){
            cout<<"Heap is empty"<<endl;
            return -1;
        }
        int max = arr[0];
        swap(arr[0],arr[last_idx]);
        last_idx--;
        int i = 0;

        while(true){
            int left_child = 2*i + 1;
            int right_child = 2*i + 2;
            int largest = i;

            if(left_child <= last_idx && arr[left_child] > arr[largest]){
                largest = left_child;
            }
            if(right_child <= last_idx && arr[right_child] > arr[largest]){
                largest = right_child;
            }
            if(largest == i){
                break;
            }
            swap(arr[i],arr[largest]);
            i = largest;
        }
        return max;
    }
};

int main() {
    max_heap myheap;
    // int arr[] = {100, 30, 50, 70, 10};
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int size = sizeof(arr)/sizeof(arr[0]);
    // myheap.make_heap_by_insertion(arr,size);
    myheap.display();
    for(int i=0;i<size;i++){
        myheap.delete_max();
        myheap.display();
    }
    for(int i=0;i<size;i++){
        cout<<myheap.arr[i]<<" ";
    }cout<<endl;

    // myheap.insert(120);
    // myheap.print_arr();
    // myheap.insert(10);
    // myheap.print_arr();
    // myheap.insert(300);
    // myheap.print_arr();
    // myheap.insert(1000000);
    // myheap.print_arr();

    return 0;
}