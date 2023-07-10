#include <iostream>
using namespace std;

class toeplitz_matrix{
    private:
        int dimension;
        int length;
        int* A;
    public:
        toeplitz_matrix(){
            length = 2;
            A = new int[length];
        }
        toeplitz_matrix(int dimension){
            this->dimension = dimension;
            length = 2*dimension-1;
            A = new int[length];
        }
        void set(int i, int j, int x);
        int get(int i, int j);
        void display();
        ~toeplitz_matrix(){
            delete[] A;
        }
};

void toeplitz_matrix::set(int i, int j, int x){
    if (i<=j){
        A[j-i] = x;
    }
    else{
        A[dimension + i - j - 1] = x;
    }
}

int toeplitz_matrix::get(int i, int j){
    if (i<=j){
        return A[j-i];
    }
    return A[dimension + i - j - 1];
}

void toeplitz_matrix::display(){
    for(int i=1;i<=dimension;i++){
        for(int j=1;j<=dimension;j++){
            if(i<=j){
                cout<<A[j-i]<<" ";
            }
            else{
                cout<<A[dimension+i-j-1]<<" ";
            }
        }
        cout<<endl;
    }
}

int main() {
    toeplitz_matrix my_matrix(5);
    my_matrix.set(1,1,2);
    my_matrix.set(1,2,3);
    my_matrix.set(1,3,4);
    my_matrix.set(1,4,5);
    my_matrix.set(1,5,6);
    my_matrix.set(2,1,7);
    my_matrix.set(2,2,2);
    my_matrix.set(2,3,3);
    my_matrix.set(2,4,4);
    my_matrix.set(2,5,5);
    my_matrix.set(3,1,8);
    my_matrix.set(3,2,7);
    my_matrix.set(3,3,2);
    my_matrix.set(3,4,3);
    my_matrix.set(3,5,4);
    my_matrix.set(4,1,9);
    my_matrix.set(4,2,8);
    my_matrix.set(4,3,7);
    my_matrix.set(4,4,2);
    my_matrix.set(4,5,3);
    my_matrix.set(5,1,10);
    my_matrix.set(5,2,9);
    my_matrix.set(5,3,8);
    my_matrix.set(5,4,7);
    my_matrix.set(5,5,2);

    for(int i=1;i<=5;i++){
        for(int j=1;j<=5;j++){
            cout<<my_matrix.get(i,j)<<" ";
        }
        cout<<endl;
    }
    cout<<"\n\n";
    my_matrix.display();
    return 0;
}

