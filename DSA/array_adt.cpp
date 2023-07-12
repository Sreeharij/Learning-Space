#include <iostream>
using namespace std;

class my_array{
    private:
        int length;
        int size;
        int* arr;
    
    public:
    my_array(int n){
        length = n;
        size = 2*n;
        arr = new int[size];
    }

    ~my_array(){
        delete[] arr;
    }

    int getlength(){
        return length;
    }

    int getsize(){
        return size;
    }

    void display(){
        for(int i=0;i<length;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    void append(int val){
        if (length<size){
            arr[length] = val;
            length++;
        }
    }

    void swap(int idx1,int idx2){
        int temp = arr[idx1];
        arr[idx1] = arr[idx2];
        arr[idx2] = temp;
    }

    void insert(int idx,int val){
        if(idx>=0 && idx<=length){
            for(int i=length;i>idx;i--){
                arr[i] = arr[i-1];
            }
            arr[idx] = val;
            length++;
        }
    }

    void accept_values(){
        for(int i=0;i<length;i++){
            cin>>arr[i];
        }
    }

    int del(int idx){
        if(idx>=0 && idx<length){
            int x = arr[idx];
            for(int i=idx;i<length-1;i++){
                arr[i] = arr[i+1];
            }
            length--;
            return x;
        }
        return -1;

    }

    int linear_search(int val){
        for(int i=0;i<length;i++){
            if(arr[i]==val){
                return i;
            }
        }
        return -1;
    }

    int transposition_linear_search(int val){
        //when element is found the element will be moved 1 index behind. That is when an element is search more times, it gets moved to the left.
        for(int i=0;i<length;i++){
            if(arr[i]==val){
                if(i==0){
                    return 0;
                }
                else{
                    swap(i,i-1);
                    return i;
                }
            }
        }
        return -1;
    }

    int movetofront_linear_search(int val){
        //when element is found, it is moved to the first index, so that subsequent searches for the element can be done in O(1) time.
        for(int i=0;i<length;i++){
            if(arr[i]==val){
                if(i==0){
                    return 0;
                }
                else{
                    swap(i,0);
                    return i;
                }
            }
        }
        return -1;
    }

    int binary_search_iterative(int key){
        //assuming array is sorted
        int low = 0;
        int high = length-1;
        int searches_performed = 0;
        int mid = 0;
        while(low<=high){
            searches_performed += 1;
            mid = (low+high)/2;
            if(arr[mid]==key){
                cout<<"Number of searches done: "<<searches_performed<<endl;
                return mid;
            }
            else if(key>arr[mid]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        cout<<"Number of searches done: "<<searches_performed<<endl;
        return -1;
    }

    int recursive_binary_search(int key,int* counter,int low,int high){
        if (low>high){
            cout<<"Number of searches done: "<<*counter<<endl;
            return -1;
        }
        int mid = (low+high)/2;
        (*counter) += 1;
        if (key==arr[mid]){
            cout<<"Number of searches done: "<<*counter<<endl;
            return mid;
        }
        else if(key > arr[mid]){
            return recursive_binary_search(key,counter,mid+1,high);
        }
        else{
            return recursive_binary_search(key,counter,low,mid-1);
        }
    }
};

int main() {
    int n;
    cout<<"Enter length of array: "<<endl;
    cin>>n;
    my_array arr(n);
    cout<<"\nArray of total size: "<<arr.getsize()<<" has been created."<<endl;
    cout<<"Enter values for first "<<arr.getlength()<<" array elements: "<<endl;
    arr.accept_values();
    cout<<"\nArray has been accepted as shown below: "<<endl;
    arr.display();
    int x;
    cin>>x;
    int counter = 0;
    cout<<"Element found at index: "<<arr.recursive_binary_search(x,&counter,0,arr.getlength())<<endl;
    
}