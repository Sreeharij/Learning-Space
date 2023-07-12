#include <iostream>
using namespace std;

class tri_diagonal_matrix{
    private:
        int dimension;
        int length;
        int* A;
    public:
        tri_diagonal_matrix(){
            length = 2;
            A = new int[length];
        }
        tri_diagonal_matrix(int dimension){
            this->dimension = dimension;
            length = 3*dimension -2;
            A = new int[length];
        }
        ~tri_diagonal_matrix(){
            delete[] A;
        }
        void set(int i, int j, int x);
        int get(int i, int j);
        void display();
};
void tri_diagonal_matrix::set(int i, int j, int x){
    if((i-j)==1){
        A[i-2] = x;
    }
    else if(i==j){
        A[dimension+i-2] = x;
    }
    else if((j-i)==1){
        A[2*dimension+i-2] = x;
    }
}

int tri_diagonal_matrix::get(int i, int j){
    if((i-j)==1){
        return A[i-2];
    }
    else if(i==j){
        return A[dimension+i-2];
    }
    else if((j-i)==1){
        return A[2*dimension+i-2];
    }
    else{
        return 0;
    }
}

void tri_diagonal_matrix::display(){
    for(int i=1;i<=dimension;i++){
        for(int j=1;j<=dimension;j++){
            if((i-j)==1){
                cout<<A[i-2]<<" ";
            }
            else if(i==j){
                cout<<A[dimension+i-2]<<" ";
            }
            else if((j-i)==1){
                cout<<A[2*dimension+i-2]<<" ";
            }
            else{
                cout<<0<<" ";

            }
        }
        cout<<endl;
    }
}

int main() {
    tri_diagonal_matrix my_matrix(5);
    my_matrix.set(1,2,1);
    my_matrix.set(2,3,2);
    my_matrix.set(3,4,3);
    my_matrix.set(4,5,4);
    my_matrix.set(1,1,5);
    my_matrix.set(2,2,6);
    my_matrix.set(3,3,7);
    my_matrix.set(4,4,8);
    my_matrix.set(5,5,9);
    my_matrix.set(2,1,10);
    my_matrix.set(3,2,11);
    my_matrix.set(4,3,12);
    my_matrix.set(5,4,13);
    my_matrix.set(1,5,100);

    cout<<my_matrix.get(1,2)<<" ";
    cout<<my_matrix.get(2,3)<<" ";
    cout<<my_matrix.get(3,4)<<" ";
    cout<<my_matrix.get(4,5)<<" ";
    cout<<my_matrix.get(1,1)<<" ";
    cout<<my_matrix.get(2,2)<<" ";
    cout<<my_matrix.get(3,3)<<" ";
    cout<<my_matrix.get(4,4)<<" ";
    cout<<my_matrix.get(5,5)<<" ";
    cout<<my_matrix.get(2,1)<<" ";
    cout<<my_matrix.get(3,2)<<" ";
    cout<<my_matrix.get(4,3)<<" ";
    cout<<my_matrix.get(5,4)<<" ";
    cout<<"\n\n";
    my_matrix.display();
    return 0;
}

