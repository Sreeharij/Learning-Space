//SOME EDGE CASES ARE NOT HANDLED YET
//INSERT AND DELETE HAVE NOT BEEN CODED YET. VERY SIMILAR TO NORMAL DOUBLY LINKED LIST
#include <iostream>
using namespace std;

struct node{
    node *prev = nullptr;
    node *next = nullptr;
    int data;
};

class circular_doubly_linked_list{
    public:
    node *first = nullptr;
    int length = 0;

    circular_doubly_linked_list(int arr[],int size){
        first = new node;
        first->data = arr[0];   
        node *ptr = first;
        node *t;
        for(int i=1;i<size;i++){
            t = new node;
            t->data = arr[i];
            ptr->next = t;
            t->prev = ptr;
            ptr = t;
        }
        t->next = first;
        first->prev = t;
        length += size;
    }

    void display(){
        node *ptr = first;
        for(int i=0;i<length;i++){
            cout<<ptr->data;
            ptr = ptr->next;
            if(i!=length-1){
                cout<<" <-> ";
            }
        }
        cout<<"\nLength of Circular Doubly Linked List = "<<length<<endl;
    }

};


int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int size = sizeof(arr)/sizeof(arr[0]);

    circular_doubly_linked_list cdll = {arr,size};
    cdll.display();
    
    return 0;
} 