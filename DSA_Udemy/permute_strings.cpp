#include <iostream>
#include <string>
using namespace std;

void permute(string letters,string temp_string,int length,int level,bool flag_arr[]){
    if(level==length){
        cout<<temp_string<<endl;
        return;
    }
    for(int i=0;i<length;i++){
        if(flag_arr[i]==0){
            flag_arr[i] = 1;
            permute(letters,temp_string+letters[i],length,level+1,flag_arr);
            flag_arr[i] = 0;
        }
    }
    return;
}

int main() {
    string letters = "123";
    string temp_string = "";
    int length = letters.length();
    bool flag_arr[length] = {0};

    permute(letters,temp_string,length,0,flag_arr);

    return 0;
}