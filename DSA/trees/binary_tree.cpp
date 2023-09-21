#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Binary_Tree{
private:
    struct Node{
        Node* lchild = nullptr;
        int data;
        Node* rchild = nullptr;
    };
public:    
    Node *root;
    Binary_Tree(){
        root = nullptr;
    }

    void CreateTree(){
        int x=0;
        Node *t,*ptr;
        queue<Node*> memory_address_queue;
        cout<<"Enter Root value: ";
        cin>>x;
        t = new Node;
        t->data = x;
        root = t;
        memory_address_queue.push(t);
        
        while(!memory_address_queue.empty()){
            ptr = memory_address_queue.front();
            memory_address_queue.pop();
            cout<<"Enter left child(-1 if no left child) of "<<ptr->data<<": ";
            cin>>x;
            if(x!=-1){
                t = new Node;
                t->data = x;
                ptr->lchild = t;
                memory_address_queue.push(t);
            }
            cout<<"Enter right child(-1 if no right child) of "<<ptr->data<<": ";
            cin>>x;
            if(x!=-1){
                t = new Node;
                t->data = x;
                ptr->rchild = t;
                memory_address_queue.push(t);
            }
        }
    }
    void Recursive_Preorder(){Recursive_Preorder(root);}
    void Recursive_Preorder(Node *ptr){
        if(ptr){
            cout<<ptr->data<<", ";
            Recursive_Preorder(ptr->lchild);
            Recursive_Preorder(ptr->rchild);
        }
    }

    void Recursive_Inorder(){Recursive_Inorder(root);}
    void Recursive_Inorder(Node *ptr){
        if(ptr){
            Recursive_Inorder(ptr->lchild);
            cout<<ptr->data<<", ";
            Recursive_Inorder(ptr->rchild);
        }
    }

    void Recursive_Postorder(){Recursive_Postorder(root);}
    void Recursive_Postorder(Node *ptr){
        if(ptr){
            Recursive_Postorder(ptr->lchild);
            Recursive_Postorder(ptr->rchild);
            cout<<ptr->data<<", ";
        }
    }

    void Levelorder(){
        Node *ptr;
        queue<Node*> memory_address_queue;
        cout<<root->data<<", ";
        memory_address_queue.push(root);
        while(!memory_address_queue.empty()){
            ptr = memory_address_queue.front();
            memory_address_queue.pop();
            if(ptr->lchild){
                cout<<ptr->lchild->data<<", ";
                memory_address_queue.push(ptr->lchild);
            }
            if(ptr->rchild){
                cout<<ptr->rchild->data<<", ";
                memory_address_queue.push(ptr->rchild);
            }
            
        }
    }

    int Height(){return Height(root);}
    int Height(Node *ptr){
        int left=0,right=0;
        if(ptr == nullptr){
            return -1;
        }
        left = Height(ptr->lchild);
        right = Height(ptr->rchild);

        int current_height = left > right ? left+1 : right+1;
        return current_height;
    }

    int Count_all_nodes(){return Count_all_nodes(root);}
    int Count_all_nodes(Node* ptr){
        int left = 0;
        int right = 0;

        if(ptr == nullptr){
            return 0;
        }
        return Count_all_nodes(ptr->lchild) + Count_all_nodes(ptr->rchild) + 1;
    }

    int Count_leaf_nodes(){return Count_leaf_nodes(root);}
    int Count_leaf_nodes(Node *ptr){
        if(ptr == nullptr){
            return 0;
        }
        if(ptr->lchild==nullptr && ptr->rchild==nullptr){
            return 1;
        }
        return Count_leaf_nodes(ptr->lchild) + Count_leaf_nodes(ptr->rchild);
    }

    int Count_deg2_nodes(){return Count_deg2_nodes(root);}
    int Count_deg2_nodes(Node *ptr){
        if(ptr == nullptr){
            return 0;
        }
        int x = Count_deg2_nodes(ptr->lchild);
        int y = Count_deg2_nodes(ptr->rchild);
        if(ptr->lchild && ptr->rchild){
            return x+y+1;
        }
        return x+y;
    }

    int Count_deg1_nodes(){return Count_deg1_nodes(root);}
    int Count_deg1_nodes(Node *ptr){
        if(ptr == nullptr){
            return 0;
        }
        int x = Count_deg1_nodes(ptr->lchild);
        int y = Count_deg1_nodes(ptr->rchild);
        if((ptr->lchild && ptr->rchild==nullptr) || (ptr->lchild==nullptr && ptr->rchild)){
            //USE BOOLEAN LOGIC TO SIMPLIFY THE ABOVE CONDITION to (ptr->lchild ^ ptr->rchild) XOR operator
            return x+y+1;
        }
        return x+y;
    }

    void Iterative_Preorder(){
        //EVEN THO THE ROOT NODE IS PUSHED TWICE INTO THE STACK THIS STILL WORKS SINCE THE STACK BECOMES EMPTY AT THE CORRECT TIME

        stack<Node*> stk;
        Node *ptr = root;
        stk.push(root);
        while(!stk.empty()){
            if(ptr == nullptr){
                ptr = stk.top();
                stk.pop();
                ptr = ptr->rchild;
            }
            else{
                cout<<ptr->data<<", ";
                stk.push(ptr);
                ptr = ptr->lchild;
            }
        }
    }

    void Iterative_Inorder(){
        stack<Node*> stk;
        Node *ptr = root;
        
        while(ptr || !stk.empty()){
            if(ptr == nullptr){
                ptr = stk.top();
                stk.pop();
                cout<<ptr->data<<", ";
                ptr = ptr->rchild;
            } 
            else{
                stk.push(ptr);
                ptr = ptr->lchild;
            }
        }
    }

    void Iterative_Postorder(){
        stack<Node*> stk;
        Node *ptr = root;
        Node *visited;

        while(ptr || !stk.empty()){
            if(ptr == nullptr){
                ptr = stk.top();
                if(ptr->rchild && ptr->rchild != visited){
                    ptr = ptr->rchild;
                }
                else{
                    cout<<ptr->data<<", ";
                    visited = ptr;
                    stk.pop(); 
                    ptr = nullptr;
                }
            }
            else{
                stk.push(ptr);
                ptr = ptr->lchild;
            }
        }
    }
};

int main(){
    Binary_Tree BT1;
    BT1.CreateTree();
    cout<<endl;
    cout<<"Recursive_Preorder: ";
    BT1.Recursive_Preorder();
    cout<<"\nRecursive_Inorder: ";
    BT1.Recursive_Inorder();
    cout<<"\nRecursive_Postorder: ";
    BT1.Recursive_Postorder();
    cout<<"\nLevelorder: ";
    BT1.Levelorder();
    cout<<"\nHeight: "<<BT1.Height()<<endl;
    // cout<<"\nCount_all_nodes: "<<BT1.Count_all_nodes()<<endl;
    // cout<<"\nCount_leaf_nodes: "<<BT1.Count_leaf_nodes()<<endl;
    // cout<<"\nCount_deg2_nodes: "<<BT1.Count_deg2_nodes()<<endl;
    // cout<<"\nCount_deg1_nodes: "<<BT1.Count_deg1_nodes()<<endl;
    cout<<"\nIterative Preorder: ";
    BT1.Iterative_Preorder();
    cout<<"\nIterative Inorder: ";
    BT1.Iterative_Inorder();
    cout<<"\nIterative Postorder: ";
    BT1.Iterative_Postorder();
    return 0;
}