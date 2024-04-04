#include <bits/stdc++.h>
#define I 9999

int main(){
    int n;
    cin>>n;
    int graph[n][n];
    int x;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>x;            
            x = x == -1 ? I : x;
            graph[i][j] = x;
        }
    }
    
    return 0;
}
