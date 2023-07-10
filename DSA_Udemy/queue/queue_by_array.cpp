#include <iostream>
using namespace std;

class queue{
public:
    int size;
    int front;
    int rear;
    int *arr;

    queue(int size){
        this->size = size;
        front = rear = -1;
        arr = new int[size];
    }
    ~queue(){
        delete[] arr;
    }

    bool isFull(){
        if(rear==size-1){
            return true;
        }
        return false;
    }

    bool isEmpty(){
        if(front==rear){
            return true;
        }
        return false;
    }

    void enqueue(int x){
        if(isFull()){
            cout<<"Queue is Full! "<<endl;
        }
        else{
            arr[++rear] = x;
        }
    }

    int dequeue(){
        int x=-1;
        if(isEmpty()){
            cout<<"Queue is Empty! "<<endl;
        }
        else{
            x = arr[++front];
        }   
        return x;
    }
    void Display(){
        for(int i=front+1;i<=rear;i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }

};

int main(){
    int arr1[] = {10,20,30,40,50};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);

    queue my_queue(size1);
    for(int i=1;i<=10;i++){
        my_queue.enqueue(10*i);
        my_queue.Display();
    }
    for(int i=0;i<10;i++){
        cout<<my_queue.dequeue()<<" has been removed."<<endl;
        my_queue.Display();
    }
    return 0;
}