//NON STANDARD IMPLEMENTATION OF BUCKET SORT FOR DECIMAL NUMBERS
#include <iostream>
using namespace std;

void print_array(double *arr,int n){
    cout<<"\n\n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n\n";
}

struct Node{
    double val;
    Node* next = nullptr;
};

void bucket_sort(double arr[],int size){
    Node* buckets[10];
    for(int i=0;i<10;i++){
        buckets[i] = nullptr;
    }
    int required_idx;
    for(int i=0;i<size;i++){
        required_idx = 10 * arr[i];
        Node* t = new Node;
        t->val = arr[i];
        if(buckets[required_idx]==nullptr){
            buckets[required_idx] = t;
        }
        else{
            Node* ptr = buckets[required_idx];
            Node* trail = nullptr;
            while(ptr != nullptr && ptr->val <= arr[i]){
                trail = ptr;
                ptr = ptr->next;
            }
            if(trail == nullptr){
                t->next = ptr;
                buckets[required_idx] = t;
            }
            else{
                trail->next = t;
                t->next = ptr;
            }
        }
    }
    int counter = 0;
    Node *ptr,*trail;
    for(int i=0;i<10;i++){
        ptr = buckets[i];
        while(ptr != nullptr){
            arr[counter++] = ptr->val;
            trail = ptr;
            ptr = ptr->next;
            delete trail;
        }
    }
    print_array(arr,size);
}

int main(){
    double arr1[] =  {0.23,0.58,0.66,0.32,0.64,0.20,0.11,0.55,0.98};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    bucket_sort(arr1,size1);

    return 0;
}