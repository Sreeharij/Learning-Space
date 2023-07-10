//LOWER TRIANGULAR MATRIX IMPLEMENTED WITH COLUMN MAJOR FORMULA

#include <iostream>
using namespace std;

class lower_triangular_matrix{
    private:
        int length;
        int dimension;
        int* A;
    public:
        lower_triangular_matrix(){
            length = 3;
            A = new int[length];
        }
        lower_triangular_matrix(int dimension){
            this->dimension = dimension;
            length = dimension*(dimension+1)/2;
            A = new int[length];
        }
        void set(int i, int j, int x);
        int get(int i, int j);
        void display();
        ~lower_triangular_matrix(){
            delete[] A;
        }
};

void lower_triangular_matrix::set(int i, int j, int x){
    if (i>=j){
        int idx = dimension*(dimension+1)/2 - (dimension - j + 1)*(dimension - j + 2)/2 + (i-j);
        A[idx] = x;
    }
}
int lower_triangular_matrix::get(int i, int j){
    if (i<j){
        return 0;
    }
    int idx = dimension*(dimension+1)/2 - (dimension - j + 1)*(dimension - j + 2)/2 + (i-j);
    return A[idx];
}

void lower_triangular_matrix::display(){
    for(int i=1;i<=dimension;i++){
        for(int j=1;j<=dimension;j++){
            if (i<j){
                cout<<0<<" ";
            }
            else{
                int idx = dimension*(dimension+1)/2 - (dimension - j + 1)*(dimension - j + 2)/2 + (i-j);
                cout<<A[idx]<<" ";
            }
        }
        cout<<endl;
    }
}

int main() {
    lower_triangular_matrix my_matrix(5);
    my_matrix.set(1,1,1);
    my_matrix.set(2,1,2);
    my_matrix.set(3,1,3);
    my_matrix.set(4,1,4);
    my_matrix.set(5,1,5);
    my_matrix.set(2,2,6);
    my_matrix.set(3,2,7);
    my_matrix.set(4,2,8);
    my_matrix.set(5,2,9);
    my_matrix.set(3,3,10);
    my_matrix.set(4,3,11);
    my_matrix.set(5,3,12);
    my_matrix.set(4,4,13);
    my_matrix.set(5,4,14);
    my_matrix.set(5,5,15);
    cout<<my_matrix.get(1,1)<<" ";    
    cout<<my_matrix.get(2,1)<<" ";
    cout<<my_matrix.get(3,1)<<" ";
    cout<<my_matrix.get(4,1)<<" ";
    cout<<my_matrix.get(5,1)<<" ";
    cout<<my_matrix.get(2,2)<<" ";
    cout<<my_matrix.get(3,2)<<" ";
    cout<<my_matrix.get(4,2)<<" ";
    cout<<my_matrix.get(5,2)<<" ";
    cout<<my_matrix.get(3,3)<<" ";
    cout<<my_matrix.get(4,3)<<" ";
    cout<<my_matrix.get(5,3)<<" ";
    cout<<my_matrix.get(4,4)<<" ";
    cout<<my_matrix.get(5,4)<<" ";
    cout<<my_matrix.get(5,5)<<" ";
    cout<<"\n\n";
    my_matrix.display();
    return 0;
}