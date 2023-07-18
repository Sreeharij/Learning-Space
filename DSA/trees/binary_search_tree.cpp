#include <iostream>
using namespace std;

struct Node{
    int val = 0;
    Node *lchild=nullptr;
    Node *rchild=nullptr;
    Node(int val){
        this->val = val;
    }
};

class binary_search_tree{
public:
    Node *root;
    binary_search_tree(){root = nullptr;}
    ~binary_search_tree(){}

    void create(int arr[],int size){
        for(int i=0;i<size;i++){
            iterative_insert(arr[i]);
        }
    }

    Node * recursive_search(Node *t,int key){
        if(t==nullptr){
            return t;
        }
        if(t->val==key){
            return t;
        }
        else if(key < t->val){
            return recursive_search(t->lchild,key);
        }
        else{
            return recursive_search(t->rchild,key);
        }
    }
    
    Node * iterative_search(int key){
        Node *t = root;
        while(t){
            if(key==t->val){
                return t;
            }
            else if(key < t->val){
                t = t->lchild;
            }
            else{
                t = t->rchild;
            }
        }
        return nullptr;
    }

    void iterative_insert(int key){
        Node *t = root;
        if(root==nullptr){
            Node *ptr = new Node(key);
            root = ptr;
            return;
        }
        Node *trail = nullptr;
        while(t){
            trail = t;
            if(t->val==key){
                return;
            }
            else if(key < t->val){
                t = t->lchild;
            }
            else{
                t = t->rchild;
            }
        }
        Node *ptr = new Node(key);
        if(key < trail->val){
            trail->lchild = ptr;
        }
        else{
            trail->rchild = ptr;
        }
    }

    Node * recursive_insert(Node *ptr,int key){
        if(ptr==nullptr){
            ptr = new Node(key);
            return ptr;
        }
        if(key < ptr->val){
            ptr->lchild = recursive_insert(ptr->lchild,key);
        }
        else{
            ptr->rchild = recursive_insert(ptr->rchild,key);
        }
        return ptr;
    }    

    void Inorder(){Inorder(root);cout<<endl;}
    void Inorder(Node *ptr){
        if(ptr==nullptr){
            return;
        }
        Inorder(ptr->lchild);
        cout<<ptr->val<<" ";
        Inorder(ptr->rchild);
    }

};

int main(){
    int arr1[] = {9,15,5,20,16,8,12,3,6,6,6,6,6,6,6};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);

    binary_search_tree bst;
    bst.create(arr1,size1);
    bst.Inorder();
    return 0;
}