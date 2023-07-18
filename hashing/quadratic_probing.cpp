#include <iostream>
#define SIZE 10
using namespace std;



class HashTable{
public:
    int *arr;

    HashTable(){
        arr = new int[10]{0};
    }
    ~HashTable(){
        delete[] arr;
    }

    int QuadraticProbe(int key){
        int idx = key%SIZE;
        int i=0;
        while(arr[(idx + i*i)%SIZE] != 0){
            i++;
            if(i>=SIZE){
                return -1;
            }
        }
        return (idx+i*i)%SIZE;
    }

    void insert(int key){
        int idx = key%SIZE;
        if(arr[idx] != 0){
            idx = QuadraticProbe(key);
        }
        arr[idx] = key;
    }

    int search(int key){
        int idx = key%SIZE;
        int i=0;
        while(arr[(idx+i*i)%SIZE] != key){
            i++;
            if(arr[(idx+i*i)%SIZE] == 0 || i>=SIZE){
                return -1;
            }
        }
        return (idx+i*i)%SIZE;
    }
};

int main() {
    int arr1[] = {16,12,25,39,6,122,5,68,75,16};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    HashTable ht;

    for(int i=0;i<size1;i++){
        ht.insert(arr1[i]);
    }

    cout << "key 25 found at: " <<ht.search(25)<< endl;
    cout << "key 35 found at: " <<ht.search(35)<< endl;
    return 0;
}