#include <iostream>
using namespace std;

long long nCr(int n,int r){
    if(r==0){
        return 1;
    }
    long long result = n;
    for(int i=0;i<r-1;i++){
        n--;
        result *= n;
        result /= i+2;
    }

    return result;
}

long long pascals_triangle(int n,int r){
    if(r==0 || n==r){
        return 1;
    }
    if(r==1){
        return n;
    }
    return pascals_triangle(n-1,r-1) + pascals_triangle(n-1,r);
}

int main(){
    
    for(int i=0;i<10;i++){
        for(int j=0;j<=i;j++){
            cout<<nCr(i,j)<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<=i;j++){
            cout<<pascals_triangle(i,j)<<" ";
        }
        cout<<endl;
    }
    
}