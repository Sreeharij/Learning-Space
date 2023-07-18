#include <iostream>
#define SIZE 10
#define PRIME 7
using namespace std;

class HashTable{
public:
    int *arr;
    HashTable(){
        arr = new int[SIZE]{0};
    }
    ~HashTable(){
        delete[] arr;
    }

    int PrimeHash(int key){
        return PRIME - (key%PRIME);
    }

    int DoubleHash(int key){
        int idx = key%SIZE;
        int i=0;
        while(arr[((idx%SIZE) + i*PrimeHash(key))%SIZE] != 0){
            i++;
            if(i >= SIZE){
                return -1;
            }
        }
        return (idx + i * (PRIME - (key%PRIME)))%SIZE;
    }

    void insert(int key){
        int idx = key%SIZE;
        if(arr[idx] != 0){
            idx = DoubleHash(key);
        }
        arr[idx] = key;
    }

    int search(int key) {
        int idx = key % SIZE;
        int i = 0;
        while (arr[(idx%SIZE + i * PrimeHash(key)) % SIZE] != key) {
            i++;
            if (arr[(idx%SIZE + i * PrimeHash(key)) % SIZE] == 0 || i >= SIZE) {
                return -1;
            }
        }
        return (idx%SIZE + i * PrimeHash(key)) % SIZE;
    }
};

int main() {
    int arr1[] = {5, 25, 15, 35, 95};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    HashTable ht;
    for(int i=0;i<size1;i++){
        ht.insert(arr1[i]);
    }
    cout << "key 25 found at: " <<ht.search(25)<< endl;
    cout << "key 100 found at: " <<ht.search(100)<< endl;
    
    return 0;
}