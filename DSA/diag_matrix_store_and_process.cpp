#include <iostream>
using namespace std;

class diag_matrix{
    private:
        int n;
        int* A;
    public:
        diag_matrix(){
            n = 2;
            A = new int[n];
        }
        diag_matrix(int n){
            this->n=n;
            A = new int[n];
        }
        void set(int i, int j, int x);
        int get(int i, int j);
        void display();
        ~diag_matrix(){
            delete[] A;
        };
};

void diag_matrix::set(int i, int j, int x){
    if (i==j){
        A[i-1] = x;
    }
}
int diag_matrix::get(int i, int j){
    if(i==j){
        return A[i-1];
    }
    else{
        
        return 0;
    }
}
void diag_matrix::display(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                cout<<A[i]<<" ";
            }
            else{
                cout<<0<<" ";
            }
        }
        cout<<endl;
    }
}

int main() {
    int n=5;
    diag_matrix my_matrix(n);
    my_matrix.set(1,1,10);
    my_matrix.set(2,2,20);
    my_matrix.set(3,3,30);
    my_matrix.set(4,4,40);
    my_matrix.set(5,5,50);
    cout<<my_matrix.get(1,1)<<" ";
    cout<<my_matrix.get(2,2)<<" ";
    cout<<my_matrix.get(3,3)<<" ";
    cout<<my_matrix.get(4,4)<<" ";
    cout<<my_matrix.get(5,5)<<" ";
    cout<<"\n\n";
    my_matrix.display();
    return 0;
}