#include <iostream>
using namespace std;

class circular_queue{
public:
    int size;
    int front;
    int rear;
    int *arr;

    circular_queue(int size){
        this->size = size+1;
        front = rear = 0;
        arr = new int[this->size];
    }
    ~circular_queue(){
        delete[] arr;
    }

    bool isEmpty(){
        if(front==rear){
            return true;
        }
        return false;
    }

    bool isFull(){
        if((rear+1)%size == front){
            return true;
        }
        return false;
    }

    void enqueue(int x){
        if(isFull()){
            cout<<"Circular Queue Overflow! "<<endl;
        }
        else{
            rear = (rear+1)%size;
            arr[rear] = x;
        }
    }

    int dequeue(){
        int x = -1;
        if(isEmpty()){
            cout<<"Circular Queue Underflow! "<<endl;
        }
        else{
            front = (front+1)%size;
            x = arr[front];
        }
        return x;
    }

    void Display(){
        if(isEmpty()){
            cout<<"Queue Empty! "<<endl;
            return;
        }
        int i=(front + 1)%size;
        while(i != (rear+1)%size){
            cout<<arr[i]<<" ";
            i = (i+1)%size;
        }cout<<endl;
    }

};

int main(){
    circular_queue cq(5);
    for(int i=1;i<=10;i++){
        cq.enqueue(10*i);
        cq.Display();
    }
    for(int i=1;i<=10;i++){
        cout<<cq.dequeue()<<" has been removed. "<<endl;
        cq.Display();
    }
    for(int i=1;i<=10;i++){
        cq.enqueue(10*i);
        cq.Display();
    }
    return 0;
}