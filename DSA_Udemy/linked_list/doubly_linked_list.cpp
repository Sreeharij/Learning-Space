//SOME EDGE CASES ARE NOT HANDLED YET

#include <iostream>
using namespace std;

struct node{
    node *prev = nullptr;
    node *next = nullptr;
    int data;
};

class doubly_linked_list{
    public:
    node *first = nullptr;
    int length = 0;

    doubly_linked_list(int arr[], int size){
        first = new node;
        first->data = arr[0];
        node *t;
        node *ptr = first;
        for(int i=1;i<size;i++){
            t = new node;
            t->data = arr[i];
            t->prev = ptr;
            ptr->next = t;
            ptr = t;
        }
        length += size;
    }

    void display(){
        node *ptr = first;
        while(ptr){
            cout<<ptr->data;
            ptr = ptr->next;
            if(ptr){
                cout<<" <-> ";
            }
        }
        cout<<"\nLength of Doubly Linked List = "<<length<<endl;
    }

    void insert(int position, int key){
        if(position > length || position < 0){
            return;
        }
        node *t = new node;
        t->data = key;
        if(position==0){
            if(first==nullptr){
                first = t;
            }
            else{
                t->next = first;
                first->prev = t;
                first = t;
            }
        }
        else{
            node *ptr = first;
            for(int i=0;i<position-1;i++){
                ptr = ptr->next;
            }
            t->next = ptr->next;
            t->prev = ptr;
            if(ptr->next){
                ptr->next->prev = t;
            }
            ptr->next = t;            
        }
        length++;
    }

    int delete_node(int position){
        if(position<1 || position > length){
            return -1;
        }
        int val = 0;
        node *ptr = first;
        if(position==1){
            val = first->data;
            first = first->next;
            if(first){
                first->prev = nullptr;
            }
            delete ptr;
        }
        else{   
            for(int i=0;i<position-1;i++){
                ptr = ptr->next;
            }
            val = ptr->data;
            ptr->prev->next = ptr->next;
            if(ptr->next){
                ptr->next->prev = ptr->prev;
            }
            delete ptr;
        }
        length--;
        return val;
    }

    void reverse_sliding_pointers(){
        node *ptr = first;
        node *trail = nullptr;
        while(ptr){
            trail = ptr;
            ptr = ptr->next;
            trail->next = trail->prev;
            trail->prev = ptr;
        }
        first = trail;
    }
};


int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int size = sizeof(arr)/sizeof(arr[0]);

    doubly_linked_list dll = {arr,size};
    dll.display();
    // dll.insert(0,500);
    // dll.display();
    // dll.insert(3,1000);
    // dll.display();
    // dll.insert(7,2000);
    // dll.display();

    // cout<<dll.delete_node(1)<<" is deleted."<<endl;
    // dll.display();

    // cout<<dll.delete_node(4)<<" is deleted."<<endl;
    // dll.display();

    // cout<<dll.delete_node(4)<<" is deleted."<<endl;
    // dll.display();
    dll.reverse_sliding_pointers();
    dll.display();
    return 0;
} 