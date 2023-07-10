#include <iostream>
using namespace std;

class stack{
public:
    int top;
    int size;
    int *arr;
   
    stack(int size){
        this->size = size;
        top = -1;
        arr = new int[size];
    }

    ~stack(){
        delete[] arr;
    }

    bool isFull(){
        if(top == size - 1){
            return true;
        }
        return false;
    }

    bool isEmpty(){
        if(top==-1){
            return true;
        }
        return false;
    }

    void push(int x){
        if(isFull()){
            cout<<"Stack is full! "<<endl;
        }
        else{
            arr[++top] = x;
        }
    }

    int pop(){
        int val = -1;
        if(isEmpty()){
            cout<<"Stack is Empty! "<<endl;
        }
        else{
            int val = arr[top--];
        }
        return val;
    }

    int stack_top(){
        if(isEmpty()){
            return -1;
        }
        return arr[top];
    }

    void display(){
        for(int i=top;i>=0;i--){
            cout<<arr[i]<<" | "<<flush;
        }
        cout<<endl;
    }

    int peek(int index){
        int val = -1;
        if(top-index+1 <0 || top-index+1 >= size){
            cout<<"Invalid index "<<endl;
        }
        else{
            val = arr[top-index+1];
        }
        return val;
    }
};


int main() {
    int values[] = {10,20,30,40,50};
    int length = sizeof(values)/sizeof(values[0]);
    int size = 10;
    stack mystack(size);

    for(int i=1;i<11;i++){
        mystack.push(i*10);
    }
    mystack.display();
    for(int i=1;i<12;i++){
        mystack.pop();
        mystack.display();
    }
    return 0;
}