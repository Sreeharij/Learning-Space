#include <bits/stdc++.h>
using namespace std;

bool dfs(int current,int source,vector<vector<int>> &adjacency_list,vector<int>& temp_visited){
    if(current == source){
        return true;
    }
    temp_visited[current]= 1;
    for(int i=0;i<adjacency_list[current].size();i++){
        if(temp_visited[adjacency_list[current][i]] == 0){
            if(dfs(adjacency_list[current][i],source,adjacency_list,temp_visited)){
                return true;
            }
        }
    }
    return false;
}

bool dual_path_present(int x,int y,vector<vector<int>> &adjacency_list){
    vector<int> temp_visited(adjacency_list.size()+1,0);
    bool x_y_path = dfs(x,y,adjacency_list,temp_visited);

    temp_visited.assign(adjacency_list.size()+1,0);
    bool y_x_path = dfs(y,x,adjacency_list,temp_visited);
    
    return x_y_path && y_x_path;
}

vector<vector<int>> get_scc(int v,vector<vector<int>> &edges){
    vector<vector<int>> adjacency_list(v+1);
    vector<vector<int>> strongly_connected_components;

    for(int i=0;i<edges.size();i++){
        adjacency_list[edges[i][0]].push_back(edges[i][1]);
    }
    vector<int> visited(v+1,0);
    
    for(int i=1;i<=v;i++){
        if(visited[i] == 0){
            vector<int> component;
            component.push_back(i);
            for(int j=i+1;j<=v;j++){
                if(visited[j] == 0 && dual_path_present(i,j,adjacency_list)){
                    visited[j] = 1;
                    component.push_back(j);
                }
            }
            strongly_connected_components.push_back(component);
        }
    }

    return strongly_connected_components;
}

int main(){
    int v = 5;
    vector<vector<int>> edges{{ 1, 3 }, { 1, 4 }, { 2, 1 }, { 3, 2 }, { 4, 5 }};

    vector<vector<int>> strongly_connected_components = get_scc(v,edges);
    for(int i=0;i<strongly_connected_components.size();i++){
        for(int j=0;j<strongly_connected_components[i].size();j++){
            cout<<strongly_connected_components[i][j]<<" ";
        }cout<<endl;
    }

    return 0;
}   