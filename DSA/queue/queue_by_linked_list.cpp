#include <iostream>
using namespace std;

struct Node{
    int val;
    Node *next = nullptr;
};

class queue_linked_list{
public:
    Node *front;
    Node *rear;

    queue_linked_list(){
        front = nullptr;
        rear = nullptr;
    }

    ~queue_linked_list(){
        Node *ptr;
        while(front){
            ptr = front;
            front = front->next;
            delete ptr;
        }
    }
    
    bool isEmpty(){
        if(front == nullptr){
            return true;
        }
        return false;
    }

    bool isFull(){
        Node *t = new Node;
        if(t==nullptr){
            return true;
        }
        delete t;
        return false;
    }

    void enqueue(int x){
        if(isFull()){
            cout<<"Queue is Full! "<<endl;
        }
        else{
            Node *t = new Node;
            t->val = x;
            if(front==nullptr){
                front = t;
                rear = t;
            }
            else{
                rear->next = t;
                rear = t;
            }
        }
    }

    int dequeue(){
        int x = -1;
        if(isEmpty()){
            cout<<"Queue is Empty! "<<endl;
        }
        else{
            Node *ptr = front;
            x = front->val;
            if(front==rear){
                front = rear = nullptr;
            }
            else{
                front = front->next;
            }
            delete ptr;
        }
        return x;
    }

    void Display(){
        Node *ptr = front;  
        while(ptr){
            cout<<ptr->val<<" ";
            ptr = ptr->next;
        }cout<<endl;
    }

};

int main(){
    queue_linked_list qll;
    for(int i=1;i<=5;i++){
        qll.enqueue(10*i);
        qll.Display();
    }
    for(int i=1;i<=10;i++){
        cout<<qll.dequeue()<<" has been removed. "<<endl;
        qll.Display();
    }
    return 0;
}                           