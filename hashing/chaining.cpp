#include <iostream>
using namespace std;

struct Node{
    int val;
    Node *next = nullptr;
    Node(int x){
        val = x;
    }
};

class HashTable{
public:
    Node **HT;

    HashTable(){
        HT = new Node*[10];
        for(int i=0;i<10;i++){
            HT[i] = nullptr;
        }
    }

    void insert(int key){
        int hash_index = key%10;
        Node *t = new Node(key);
        if(HT[hash_index]==nullptr){
            HT[hash_index] = t;
        }
        else{
            Node *ptr = HT[hash_index];
            Node *trail = nullptr;
            while(ptr && ptr->val < key){
                trail = ptr;
                ptr = ptr->next;
            }
            if(trail==nullptr){
                t->next = HT[hash_index];
                HT[hash_index] = t;
            }
            else{
                t->next = trail->next;
                trail->next = t;
            }
            
        }
    }

    int search(int key){
        int hash_index = key%10;
        Node *ptr = HT[hash_index];
        while(ptr && ptr->val <=key){
            if(ptr->val == key){
                return key;
            }
            ptr = ptr->next;
        }
        return -1;
    }

    ~HashTable(){
        Node *ptr = nullptr;
        for(int i=0;i<10;i++){
            while(HT[i]){
                ptr = HT[i];
                HT[i] = HT[i]->next;
                delete ptr;
            }
        }
        delete[] HT;
    }

};

int main() {
    int arr1[] = {16,12,25,39,6,122,5,68,75,16};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    HashTable ht;
    for(int i=0;i<size1;i++){
        ht.insert(arr1[i]);
    }

    cout<<"Searching for 6. "<<ht.search(6)<<" found."<<endl;
    cout<<"Searching for 4. "<<ht.search(4)<<" found."<<endl;
    return 0;
}