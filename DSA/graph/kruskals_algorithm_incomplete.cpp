#include <bits/stdc++.h>
#define I INT_MAX
using namespace std;

int find(int u,int set[]){
    while(set[u] > 0){
        u = set[u];
    }
}

void get_union(int u,int v,int set[]){

}

int main(){
    int v=7;
    int e=9;

    int edges[3][e] = {{ 1, 1,  2,  2, 3,  4,  4,  5,  5},
                       { 2, 6,  3,  7, 4,  5,  7,  6,  7},
                       {25, 5, 12, 10, 8, 16, 14, 20, 18}};

    int track[e] = {0};
    int set[v+1] = {-1,-1,-1,-1,-1,-1,-1,-1};
    int t[2][v-1];

    int i=0;
    int min,k,u,v;
    while(i < v-1){
        min = I;
        for(int j=0;j<e;j++){
            if(track[j] == 0 && edges[2][j] < min){
                min = edges[2][j];
                k = j;
                u = edges[0][j];
                v = edges[1][j];
            }
        }
        if(find(u,set) != find(v,set)){
            t[0][i] = u;
            t[1][i] = v;

            get_union(find(u,set),find(v,set),set);
            i++;
        }
        track[k] = 1;
    }
}