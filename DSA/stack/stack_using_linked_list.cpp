#include <iostream>
using namespace std;

class node{
public:
    int data;
    node* next = nullptr;
};

class stack{
private:
    node *top;
public:
    stack(){
        top = nullptr;
    }

    ~stack(){
        node *ptr;
        while(top){
            ptr = top;
            top = top->next;
            delete ptr;
        }   
    }

    void push(int x){
        node *t =  new node;
        if(t==nullptr){
            cout<<"Stack Overflow "<<endl;
        }
        else{
            t->data = x;
            t->next = top;
            top = t;
        }
    }

    int pop(){
        int val = -1;
        if(top==nullptr){
            cout<<"Stack Underflow "<<endl;
        }
        else{
            val = top->data;
            node *ptr = top;
            top = top->next;
            delete ptr;
        }
        return val;
    }

    bool isEmpty(){
        if(top==nullptr){
            return true;
        }
        return false;
    }
    
    bool isFull(){
        node *t = new node;
        bool result = t ? 0:1;
        delete t;
        return result;
    }

    int stacktop(){
        if(top){
            return top->data;
        }
        return -1;
    }

    int peek(int index){
        if(isEmpty()){
            return -1;
        }
        node *t = top;
        for(int i=0;i<index-1 && t!=nullptr;i++){
            t = t->next;
        }
        if(t!=nullptr){
            return t->data;
        }
        return -1;
    }

    void display(){
        node *t = top;
        if(isEmpty()){
            cout<<"Stack Empty! "<<endl;
        }
        else{
            while(t){
                cout<<t->data<<" ";
                t = t->next;
            }
            cout<<endl;
        }
    }


};


int main() {
    int arr[] = {10,20,30,40,50};
    int size = sizeof(arr)/sizeof(arr[0]);

    stack my_stack;
    for(int i=1;i<=10;i++){
        my_stack.push(10*i);
        my_stack.display();
    }
    for(int i=1;i<=11;i++){
        cout<<my_stack.peek(i)<<endl;
    }

    return 0;
}