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


    void print_arr(){
        for(int i=0;i<last_idx;i++){
            cout<<arr[i]<<" ";
        }cout<<"\n\n";
    }
};

int main() {
    max_heap myheap;
    myheap.insert(10);
    myheap.print_arr();
        myheap.insert(5);
    myheap.print_arr();
        myheap.insert(12);
    myheap.print_arr();
        myheap.insert(1);
    myheap.print_arr();
        myheap.insert(100);
    myheap.print_arr();

    return 0;
}
