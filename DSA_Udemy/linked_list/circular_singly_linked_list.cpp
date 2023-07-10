//SOME EDGE CASES ARE NOT HANDLED YET

#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;  
};

class circular_singly_linked_list{
    public:
    node* first = nullptr;
    int length = 0;

    circular_singly_linked_list(int arr[],int size){
        first = new node;
        first->data = arr[0];
        first->next = nullptr;

        length = 1;

        node *ptr = first;
        node *t;
        for(int i=1;i<size;i++){
            t = new node;
            t->data = arr[i];
            t->next = nullptr;
            ptr->next = t;
            ptr = t;
            length++;
        }
        ptr->next = first;
    }

    void display(){
        node *ptr = first;
        do{
            cout<<ptr->data<<" ";
            ptr = ptr->next;
        }while(ptr != first);
        cout<<"\nLength of the circular_singly_linked_list: "<<length<<endl;
    }

    void recursive_display(node *ptr){
        static bool flag = 0;
        if(ptr==first && flag){
            cout<<"\nLength of the circular_singly_linked_list(recursive display): "<<length<<endl;
            flag = 0; //resetting flag value since flag is static (for further function calls in main program)
            return;
        }
        cout<<ptr->data<<" ";
        flag = 1;
        recursive_display(ptr->next);
    }

    void insert(int position, int key){
        //INSERTS AFTER SPECIFIED POSITION. 1 BASED INDEXING
        if (position>length || position < 0){
            return;
        }
        node *t = new node;
        t->data = key;
        if(position==0){
            if(first == nullptr){
                first = t;
                first->next = first;
            }
            else{
                node *ptr = first;
                for(int i=0;i<length-1;i++){
                    ptr = ptr->next;
                }
                t->next = first;
                ptr->next = t;
                first = t;
                length++;
            }
        }
        else{
            node *ptr = first;
            for(int i=0;i<position-1;i++){
                ptr = ptr->next;
            }
            t->next = ptr->next;
            ptr->next = t;
            length++;
        }
    }

    int delete_node(int position){
        if(position>length || position<1){
            return -1;
        }
        node *ptr = first;
        node *trail = nullptr;
        int val = 0;
        if(position==1){
            for(int i=0;i<length-1;i++){
                ptr = ptr->next;
            }
            val = first->data;
            if(first==ptr){
                delete first;
                first = nullptr;
            }
            else{
                ptr->next = first->next;
                delete first;
                first = ptr->next;
            }
            
        }
        else{
            for(int i=0;i<position-1;i++){
                trail = ptr;
                ptr = ptr->next;
            }
            trail->next = ptr->next;
            val = ptr->data;
            delete ptr;
        }
        length--;
        return val;
    }
};


int main(){
    int arr[] = {10,20,30,40,50};
    int size = sizeof(arr)/sizeof(arr[0]);

    circular_singly_linked_list cll = {arr,size};
    cll.recursive_display(cll.first);

    cll.insert(0,2000);
    cll.insert(6,500);
    cll.display();

    cout<<cll.delete_node(4)<<" deleted."<<endl;
    cll.display();
    cout<<cll.delete_node(6)<<" deleted."<<endl;
    cll.display();

    return 0;
} 