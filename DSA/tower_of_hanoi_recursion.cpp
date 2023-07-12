#include <iostream>
using namespace std;

char arr[3] = {'A','B','C'};

void tower_of_hanoi(int n,int source, int destination, int auxilary){
    if(n==1){
        cout<<"Move "<<n<<" from plate "<<arr[source-1]<<" to plate "<<arr[destination-1]<<endl;
        return;
    }
    tower_of_hanoi(n-1,source,auxilary,destination);
    cout<<"Move "<<n<<" from plate "<<arr[source-1]<<" to plate "<<arr[destination-1]<<endl;
    tower_of_hanoi(n-1,auxilary,destination,source);
}


int main(){
    tower_of_hanoi(10,1,3,2);
    return 0;
}