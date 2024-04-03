#include <iostream>
#include <vector>
using namespace std;

class max_heap{
private:
    int *arr;
    int last_idx;
    int array_max_size = 100;

public:
    max_heap(){
        arr = new int[array_max_size];
        for(int i=0;i<array_max_size;i++){
            arr[i] = 0;
        }
        last_idx = 0;
    }
    ~max_heap(){
        delete[] arr;
    }

    void insert(int key){
        int i = last_idx;
        while(i>0 && key > arr[(i+1)/2 - 1]){
            arr[i] = arr[(i+1)/2 - 1];
            i = (i+1)/2 - 1;
        }
        arr[i] = key;
        last_idx++;
    }

    void swap(int &a,int &b){
        int temp = a;
        a = b;
        b = temp;
    }

    void delete_max(){
        int i = last_idx - 1;
        swap(arr[i],arr[0]);
        last_idx--;
        slide_down();
    }

    void slide_down(){
        int current = 0;
        int left_child;
        int right_child;
        while(current*2 + 1 < last_idx){
            left_child = current*2 + 1;
            right_child = current*2 + 2;
            int larger_child = left_child;
            if(right_child < last_idx){
                larger_child = arr[right_child] > arr[left_child] ? right_child : left_child;
            }
            if(arr[current] < arr[larger_child]){
                swap(arr[current],arr[larger_child]);
                current = larger_child;
            }
            else{
                break;
            }
        }
    }

    void make_heap_by_insertion(int given_arr[],int size){
        for(int i=0;i<size;i++){
            this->insert(given_arr[i]);
        }
    }


    void print_arr(){
        for(int i=0;i<last_idx;i++){
            cout<<arr[i]<<" ";
        }cout<<"\n\n";
    }
};

int main() {
    max_heap myheap;
    int arr[] = {10,5,12,1,100,1000};
    int size = sizeof(arr)/sizeof(arr[0]);
    myheap.make_heap_by_insertion(arr,size);
    myheap.print_arr();
    for(int i=0;i<6;i++){
        myheap.delete_max();
        myheap.print_arr();
    }
    myheap.insert(120);
    myheap.print_arr();
    myheap.insert(10);
    myheap.print_arr();
    myheap.insert(300);
    myheap.print_arr();
    myheap.insert(1000000);
    myheap.print_arr();

    return 0;
}
