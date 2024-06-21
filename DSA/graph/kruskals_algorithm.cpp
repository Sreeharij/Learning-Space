#include <bits/stdc++.h>
#define I INT_MAX
using namespace std;

static bool sort_by_weight(const vector<int>& x,const vector<int>& y){
    return x[2] < y[2];
}

int find(int u,vector<int>& set){
    if(set[u] < 0)return u;
    else{
        set[u] = find(set[u],set);
        return set[u];
    }
}

void get_union(int u,int v,vector<int>& set){
    int u_parent = find(u,set);
    int v_parent = find(v,set);
    if(abs(set[u_parent]) < abs(set[v_parent])){
        set[v_parent] += set[u_parent];
        set[u_parent] = v_parent;
    }
    else{
        set[u_parent] += set[v_parent];
        set[v_parent] = u_parent;
    }
}

int main(){
    vector<vector<int>> edges = {{1,2,25},{1,6,5},{2,3,12},{2,7,10},{3,4,8},{4,5,16},{4,7,14},{5,6,20},{5,7,18}};
    sort(edges.begin(),edges.end(),sort_by_weight);
    vector<int> set(7+1,-1);
    for(int i=0;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];
        if(find(u,set) != find(v,set)){
            cout << u << " " << v << " " << weight << endl;
            get_union(u,v,set);
        }
    }
}