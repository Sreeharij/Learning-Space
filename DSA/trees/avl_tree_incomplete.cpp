#include <iostream>>

class AVL_Tree{
private:
    struct Node{
        Node* lchild = nullptr;
        Node* rchild = nullptr;
        int data;
    }; 

public:
    Node* root;
    AVL_Tree(){root = nullptr;}
    ~AVL_Tree(){}

    Node* recursive_insert(Node* ptr,int key){
        if(!ptr){
            ptr = new Node();
        }
    }
};

int main(){


    return 0;
}