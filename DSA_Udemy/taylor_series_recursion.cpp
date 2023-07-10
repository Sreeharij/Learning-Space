#include <iostream>
using namespace std;

double taylor_series_recursion(int current_level,int n,int x,double factorial,double power_of_x){
    if(n==1){
        return 1;
    }
    if (current_level==0){
        return 1 + taylor_series_recursion(current_level + 1,n,x,factorial,power_of_x);
    }
    if(current_level==n-1){
        power_of_x = power_of_x*x;
        factorial = factorial * current_level;        
        return power_of_x/factorial;
    }

    power_of_x = power_of_x * x;
    factorial = factorial * current_level;
    return power_of_x/factorial + taylor_series_recursion(current_level + 1,n,x,factorial,power_of_x);    
}

int main(){
    int n,x;
    cin>>n>>x;
    cout<<taylor_series_recursion(0,n,x,1,1)<<endl;
    return 0;
}

