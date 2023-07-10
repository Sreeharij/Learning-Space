//SOME EDGE CASES ARE NOT HANDLED YET

#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;  
};

class singly_linked_list{
    public:
    node* first = nullptr;
    int length = 0;

    singly_linked_list(int arr[], int size) {
        first = new node;
        first->data = arr[0];
        first->next = nullptr;
        length++;

        node* t, * ptr;
        ptr = first;
        for (int i = 1; i < size; i++) {
            t = new node;
            t->data = arr[i];
            t->next = nullptr;
            ptr->next = t;
            ptr = t;
            length++;
        }
    }

    void display(){
        node* ptr = first;
        while(ptr){
            cout<<ptr->data<<" ";
            ptr = ptr->next;
        }
        cout<<endl;
        cout<<"Length of linked_list = "<<length<<endl;
    }

    void recursive_display(node* ptr){
        if(ptr){
            cout<<ptr->data<<" ";
            return recursive_display(ptr->next);    
        }
        cout<<endl;
    }

    int count(){
        int counter = 0;
        node *ptr = first;
        while(ptr){
            counter++;
            ptr = ptr->next;
        }
        return counter;
    }

    int recursive_count(node *ptr){
        if(ptr){
            return 1 + recursive_count(ptr->next);
        }
        return 0;
    }

    int sum(){
        int sum_counter = 0;
        node* ptr = first;
        while(ptr){
            sum_counter += ptr->data;
            ptr = ptr->next;
        }
        return sum_counter;
    }

    int recursive_sum(node* ptr){
        if(ptr){
            return ptr->data + recursive_sum(ptr->next);
        }
        return 0;
    }

    int max(){
        node *ptr = first;
        int max_val = ptr->data;
        ptr = ptr->next;
        while(ptr){
            if(ptr->data > max_val){
                max_val = ptr->data;
            }
            ptr = ptr->next;
        }
        return max_val;
    }

    int recursive_max(node *ptr){
        int max_val = 0;
        if(ptr){
            max_val = recursive_max(ptr->next);
            if(ptr->data > max_val){
                return ptr->data;
            }
            return max_val;
        }
        return first->data;
    }

    node* linear_search(int key){
        node *ptr = first;
        while(ptr){
            if(ptr->data == key){
                return ptr;
            }
            ptr = ptr->next;
        }
        return nullptr;
    }

    node* linear_search_move_front(int key){
        if(first->data == key){
            return first;
        }
        node *ptr = first;
        node *q = nullptr;
        while(ptr){
            if (ptr->data == key){
                q->next = ptr->next;
                ptr->next = first;
                first = ptr;
                return ptr;
            }
            q = ptr;
            ptr = ptr->next;
        }
        return nullptr;
    }

    node* recursive_search(node *ptr,int key){
        if(ptr==nullptr){
            return nullptr;
        }
        if(ptr->data==key){
            return ptr;
        }
        return recursive_search(ptr->next,key);
    }

    void insert(int position,int key){
        // 1 BASED INDEXING, value will be inserted after specified index
        node *ptr = first;
        node* t = new node;
        t->data = key;
        if (position>length || position < 0){
            return;
        }
        else if(position==0){
            t->next = first;
            first = t;
        }
        else{
            for(int i=0;i<position-1;i++){
                ptr = ptr->next;
            }
            t->next = ptr->next;
            ptr->next = t;
        }
        length++;
    }

    void sorted_insert(int key){
        node *ptr = first;
        node *trail = nullptr;
        node *t = new node;
        t->data = key;
        if (first==nullptr){
            first = t;
        }
        else{
            while(ptr && key > ptr->data){ 
            //order of the conditions in the loop should be maintained, else when ptr becomes null(key is greater than all elements),
            //or else it tries to dereference a null pointer leading to program crash.
                trail = ptr;
                ptr = ptr->next;
            }
            if(ptr==first){
                t->next = first;
                first = t;
            }
            else{
                trail->next = t;
                t->next = ptr;
            }
        } 
        length++;
    }

    int delete_node(int position){
        node *ptr = first;
        node *trail = nullptr;
        int val = 0;
        if(position>length || position<1){
            return -1;
        }
        if(position==1){
            val = first->data;
            first = first->next;
            delete ptr;
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

    bool isSorted(){
        node *ptr = first;
        int prev = first->data;
        while(ptr){
            if(ptr->data < prev){
                return 0;
            }
            prev = ptr->data;
            ptr = ptr->next;
        }
        return 1;
    }

    void remove_duplicate_sorted_ll(){
        node *ptr = first->next;
        node *trail = first;
        while(ptr){
            if(ptr->data == trail->data){
                trail->next = ptr->next;
                delete ptr;
                length--;
                ptr = trail->next;
            }
            else{
                trail = ptr;
                ptr = ptr->next;
            }           
        }
    }

    void reverse_sliding_pointers(){
        node *p=first,*q=nullptr,*r=nullptr;
        while(p){
            r=q;
            q=p;
            p = p->next;
            q->next = r;
        }
        first = q;
    }

    void recursive_reverse(node *ptr, node *trail){
        if(ptr==nullptr){
            first = trail;
            return;
        }
        recursive_reverse(ptr->next, ptr);
        ptr->next = trail;
    }


    void concatenate(singly_linked_list *list2){
        node *ptr = first;
        node *trail = nullptr;
        while(ptr){
            trail = ptr;
            ptr = ptr->next;
        }
        trail->next = list2->first;
        length += list2->length;
    }

    void merge(singly_linked_list *list2){
        //MERGES AND REMOVES DUPLICATES
        node *ptr1 = first;
        node *ptr2 = list2->first;
        node *last = nullptr;
        if(ptr1->data < ptr2->data){
            last = ptr1;
            ptr1 = ptr1->next;
        }
        else{
            last = ptr2;
            ptr2 = ptr2->next;
        }
        while(ptr1 && ptr2){
            if(ptr1->data < ptr2->data){
                last->next = ptr1;
                ptr1 = ptr1->next;
            }
            else if(ptr2->data < ptr1->data){
                last->next = ptr2;
                ptr2 = ptr2->next;
            }
            else{
                last->next = ptr1;
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
            last = last->next;
        }
        if(ptr1){
            last->next = ptr1;
        }
        if(ptr2){
            last->next = ptr2;
        }

        first = first->data < list2->first->data ? first : list2->first;

        length = 0;
        ptr1 = first;
        while(ptr1){
            length++;
            ptr1 = ptr1->next;
        }
    }

    void make_loop(int position){
        //ONLY FOR TEST PURPOSES
        node *ptr = first;
        node *save_address;
        for(int i=0;i<position-1;i++){
            ptr = ptr->next;
        }
        save_address = ptr;
        for(int i=position;i<length;i++){
            ptr = ptr->next;
        }
        cout<<"To check we reached end "<<ptr->next<<endl;
        ptr->next = first;
    }

    bool checkLoop(){
        node *slow=first;
        node *fast = first;
        do{
            slow = slow->next;
            fast = fast->next;
            if(fast){
                fast = fast->next;
            }
        }while(fast && fast!=slow);

        if (fast==slow){
            return true;
        }
        return false;
    }
};

int main() {
    int arr[] = {15,20,30,40,50};
    int arr2[] = {10,20,35,4000};
    int size = sizeof(arr)/sizeof(arr[0]);
    int size2 = sizeof(arr2)/sizeof(arr2[0]);
    
    singly_linked_list ll = {arr,size};
    singly_linked_list ll2 = {arr2,size2};
    ll.remove_duplicate_sorted_ll();
    ll2.remove_duplicate_sorted_ll();
    ll.display();
    ll2.display();

    ll.merge(&ll2);
    ll.display();

    bool flag;

    ll.make_loop(3); //connects the end of ll to third node (1 based indexing)

    flag = ll.checkLoop();
    if (flag){
        cout<<"Loop present"<<endl;
    }
    else{
        cout<<"No Loop"<<endl;
    }

    // ll.recursive_reverse(ll.first,nullptr);
    // ll.display();
    // ll.sorted_insert(555);
    // cout<<"Value at node index(1 based indexing): "<<3<<" is = "<<ll.delete_node(3)<<endl;
    // ll.display();

    // bool flag = ll.isSorted();
    // if (flag){
    //     cout<<"LL is Sorted"<<endl;
    // }
    // else{
    //     cout<<"LL is NOT Sorted"<<endl;
    // }


    // ll.recursive_display(ll.first);
    // cout<<"Number of elements: "<<ll.count()<<endl;
    // cout<<"Number of elements(recursive): "<<ll.recursive_count(ll.first)<<endl;
    // cout<<"Sum of elements: "<<ll.sum()<<endl;
    // cout<<"Sum of elements(recursive): "<<ll.recursive_sum(ll.first)<<endl;
    // cout<<"Maximum Value: "<<ll.max()<<endl;
    // cout<<"Maximum Value(recursive): "<<ll.recursive_max(ll.first)<<endl;
    // int key = 40;
    // cout<<"Key: "<<key<<" found at address: "<<ll.linear_search(key)<<endl;
    // cout<<"Recursive search, key: "<<key<<" found at address: "<<ll.recursive_search(ll.first,key)<<endl;

    // cout<<"Key: "<<10<<" Address: "<<ll.linear_search(10)<<endl;
    // cout<<"Key: "<<20<<" Address: "<<ll.linear_search(20)<<endl;
    // cout<<"Key: "<<30<<" Address: "<<ll.linear_search(30)<<endl;
    // cout<<"Key: "<<40<<" Address: "<<ll.linear_search(40)<<endl;
    // cout<<"Key: "<<50<<" Address: "<<ll.linear_search(50)<<endl;

    // key = 10;
    // cout<<"\nOptimised search for key: "<<key<<" found at address: "<<ll.linear_search_move_front(key)<<endl;
    // ll.display();
    // key = 40;
    // cout<<"\nOptimised search for key: "<<key<<" found at address: "<<ll.linear_search_move_front(key)<<endl;
    // ll.display();
    // key = 30;
    // cout<<"\nOptimised search for key: "<<key<<" found at address: "<<ll.linear_search_move_front(key)<<endl;
    // ll.display();
    // key = 20;
    // cout<<"\nOptimised search for key: "<<key<<" found at address: "<<ll.linear_search_move_front(key)<<endl;
    // ll.display();
    // key = 10;
    // cout<<"\nOptimised search for key: "<<key<<" found at address: "<<ll.linear_search_move_front(key)<<endl;
    // ll.display();

    return 0;
} 